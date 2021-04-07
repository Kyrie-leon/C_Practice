#include"comm.h"

int main()
{
  //获取一个唯一标识内存的key值
  key_t key = ftok(PATHNAME, PROJ_ID);
  if(key < 0)
  {
    perror("ftok");
    return 1;
  }
  //创建共享内存
  int shmid = shmget(key,SIZE,0);
  //关联共享内存
  char * addr = shmat(shmid, NULL, 0);
  int i = 0;
  while(i < 26)
  {
    addr[i] = 'A' + i;
    i++;
    addr[i] = 0;
    sleep(1);
  }
  //取消共享内存
  shmdt(addr);
  sleep(5);
  return 0;
}
