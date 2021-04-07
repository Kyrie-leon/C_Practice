#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

int main()
{
  int pipefd[2] = {0};
  int ret = pipe(pipefd);
  if(ret==-1)
  {
    perror("pipe");
    return 1;
  }

  pid_t id = fork();
  if(id < 0)
  {
    perror("fork");
    return 1;
  }
  //父进程读取
  else if(id > 0)
  {
    //父进程关闭写文件描述符
    close(pipefd[1]);
    char buf[64];
    int count  = 0;
    while(1)
    {
      ssize_t s = read(pipefd[0],buf,sizeof(buf)-1);
      if(s > 0)
      {
        buf[s] = 0;
        printf("father get a msg:%s\n",buf);
        sleep(1);
      } 
      //3秒后关闭读端
      if(count++ == 3)
      {
        close(pipefd[0]);
        break;
      }
    }
  }
  
  //子进程写入i am child
  else
  {
    //子进程关闭读文件描述符
    close(pipefd[0]);
    const char *msg = "i am child\n";
    int count =0;
    while(1)
    {
      write(pipefd[1],msg,strlen(msg));
      printf("write a msg:%d\n",count++);
      sleep(1);
    }
  }
  int status = 0;
  waitpid(id,&status,0);
  printf("child get a sig:%d\n",status&0x7f);

  return 0;
}
