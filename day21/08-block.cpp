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
    pid_t ret = waitpid(-1, &status,0);
    if(ret == id && WIFEXITED(status))
    {
      cout<<"wait child 10s success, child exit code: "<<WEXITSTATUS(status)<<endl;
    }
    else
    {
      cout<<"wait child failed"<<endl;
    }
  }
    

  return 0;
}
