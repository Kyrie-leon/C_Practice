#include<stdio.h>
#include<unistd.h>

int main()
{
  int fd[2] = {0};
  int ret = pipe(fd);
  printf("ret:%d\n",ret);
  printf("fd[0]:%d\n",fd[0]);
  printf("fd[1]:%d\n",fd[1]);

  return 0;
}
