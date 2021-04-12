#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

int main()
{
  pid_t pid = getpid();
  while(1)
  {
    printf("getpid:%d\n",pid);
    abort();
  }
  return 0;
}
