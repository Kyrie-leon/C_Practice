#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
  printf("begin......\n");
  char *env[] ={
    "myenv=you_can_see_me",
    NULL
  };
  execle("./mycmd", "./mycmd",NULL, env);
  printf("after....\n");
  return 0;
}
