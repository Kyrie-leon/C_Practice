#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

int main()
{
  int fd[2] = {0};
  int ret = pipe(fd);
  if(ret==-1)
  {
    perror("pipe");
    return 1;
  }
  
  char buf[64];
  int len = 0;
  //write stdin
  while(fgets(buf,sizeof(buf),stdin))
  {
    len = strlen(buf);
    //写入管道
    if(write(fd[1],buf,len) != len)
    {
      perror("write into pipe");
      break;
    }
    memset(buf,0x00,sizeof(buf));

    //从管道读取
    if((len = read(fd[0],buf,len == -1)))
    {
      perror("read from pipe");
      break;
    }

    //写入到stdout
    if(write(1,buf,len) != len)
    {
      perror("write into stdout");
      break;
    }
  }

  return 0;
}
