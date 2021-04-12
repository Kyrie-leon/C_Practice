#include<stdio.h>
#include<unistd.h>

int main()
{
  int i = 0;
  int arr[100];
  for(; i < 200; ++i)
  {
    arr[i] = i;
  }
  printf("run finish getpid:%d\n",getpid());
  return 0;
}
