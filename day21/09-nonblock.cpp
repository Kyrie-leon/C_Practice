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
    cout<<"child is running..."<<endl;
    sleep(10);
    exit(10);
  }

  if(id > 0)
  {
    int status=0;
    pid_t ret =0;
    do
    {
      ret = waitpid(-1, &status,WNOHANG);
      if(ret ==0 )
      {
        cout<<"child is running"<<endl;
      }
      sleep(1);
    }while(ret == 0);

    if(WIFEXITED(status) && ret == id)
    {
      cout<<"wait child 10s success, child return code:"<<WEXITSTATUS(status)<<endl;
    }
    else
    {
      cout<<"wait child failed,"<<endl;
      return 1;
    }
  }
    

  return 0;
}
