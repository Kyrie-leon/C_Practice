#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

#define FIFO_FILE "./fifo"

int main()
{
  umask(0);
  if(-1 == mkfifo(FIFO_FILE,0666))
  {
    perror("mkfifo");
    return 1;
  }
  
  pid_t id = fork();

  if(id < 0)
  {
    perror("fork!");
    return 1;
  }
  else if(id > 0)
  { 
    int fd = open(FIFO_FILE, O_RDONLY); 
    if(fd < 0)
    {
      perror("open");
      return 1;
    }
    else
    {
      while(1)
      {
        char buf[1024];
        ssize_t s = read(fd,buf,sizeof(buf)-1);
        if(s > 0)
        {
          buf[s] = 0;
          printf("#############################\n");
          printf("client#:%s\n",buf);
          sleep(5);
        }
        else
       {
          close(fd);
          printf("server offline!\n");
          break;
        }
      }
    } 
  }
  else
  {
    int fd = open(FIFO_FILE,O_WRONLY);
    char * msg = "i am process A\n";
    while(1)
    {
      ssize_t s = write(fd, msg, strlen(msg));
      sleep(5);
    }
  }
  return 0;
}
