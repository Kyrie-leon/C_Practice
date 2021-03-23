#include<iostream>
#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>
using namespace std;

int main()
{
  pid_t id =fork();
  if(id < 0)
  {
    perror("fork error");
    exit(1);
  }
  
  if(id == 0)
  {
    sleep(10);
    exit(10);
  }

  if(id > 0)
  {
    int st;
    int ret = waitpid(id, &st,0);
    if(ret > 0 && (st & 0x7f) == 0)
    {
      cout<<"child exit code: "<<((st >> 8)&0xFF)<<endl;
    }
    else if(ret > 0)
    {
      cout<<"sig code: "<<(st & 0x7F)<<endl;
    }
  }
    

  return 0;
}
