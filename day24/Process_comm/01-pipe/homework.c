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
  if(id == 0)
  {
    close(pipefd[1]);
    char buf[64];
    while(1)
    {
      ssize_t s = read(pipefd[0],buf,sizeof(buf)-1);
      if(s > 0)
      {
        buf[s] = 0;
        printf("father get a msg:%s\n",buf);
        sleep(1);
      } 
    }
  }
  
  if(id > 0)
  {
    close(pipefd[0]);
    const char *msg = "i am child";
    while(1)
    {
      write(pipefd[1],msg,strlen(msg));
      sleep(1);
    }
  }

  return 0;
}
