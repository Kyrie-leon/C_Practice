#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<iostream>
using namespace std;

int main()
{
  pid_t id =fork();

  if(id < 0)
  {
    cout<<"fork error"<<endl;;
    return 1;
  }

  if(id == 0)
  {
    int count = 0;
    while(1)
    {
      sleep(1);
      cout<<"child.........."<<endl;
      if(count >= 5)
      {
        break;
      }
      count++;
    }
    exit(0);
  }
  //父进程
  if(id > 0)
  {
    cout<<"father...."<<endl;
    wait(NULL);//父进程阻塞等待，等待子进程退出后，父进程退出
    cout<<"after father...."<<endl;
  }
  return 0;
}
