#include<unistd.h>

int main()
{
  //execl("/usr/bin/ls","ls","-a","-l",NULL);

  //带p的，可以使用环境变量无需写路径
  //execlp("ls","ls","-a","-l",NULL);

  //execv需要讲参数放入到列表当中
  char *const argv[] = {"ls","-a","-l",NULL};
  //execv("/usr/bin/ls",argv);
  //带p的无需写全路径，可以使用环境变量
  execvp("ls",argv);


  return 0;
}
