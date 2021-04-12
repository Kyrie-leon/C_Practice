#include<stdio.h>
#include<unistd.h>

int main()
{
  int count = 1;
  alarm(1);
  while(1)
  {
    printf("count = %d\n",count++);
  }
  return 0;
}
