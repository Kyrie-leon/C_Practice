#include <stdlib.h>
#include <stdio.h>
int main()
{
  printf("myenv:%s\n", getenv("myenv"));
  return 0;
}
