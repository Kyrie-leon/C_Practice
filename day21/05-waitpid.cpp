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
    int count = 1;
    while(count < 20)
    {
      cout<<"child is running...."<<endl;
      ++count;
    }

  }
  //父进程
  if(id > 0)
  {
    cout<<"father...."<<endl;
    int ret = waitpid(id,NULL,0);
    if(ret == id)
    {
      cout<<"等待成功"<<endl;
    }
    else
    {
      cout<<"等待失败"<<endl;
    }
    cout<<"after father...."<<endl;
  }
  return 0;
}
