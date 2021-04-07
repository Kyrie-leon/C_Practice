#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

#define FIFO_FILE "./fifo"

int main()
{
  
  int fd = open(FIFO_FILE,O_WRONLY);
  if(fd < 0)
  {
    perror("open");
    return 1;
  }
  else
  {

    while(1)
    {
      printf("Please Input Your Message:");
      fflush(stdout);
      char msg[1024];
      //从键盘读取信息
      ssize_t s = read(0,msg,sizeof(msg)-1);
      if(s > 0)
      {
        msg[s] = 0;
        write(fd,msg,strlen(msg));
      }
    }
  }
  return 0;
}
