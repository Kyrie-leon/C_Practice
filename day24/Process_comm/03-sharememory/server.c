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
  int shmid = shmget(key,SIZE,IPC_CREAT|IPC_EXCL|0666);
  //关联共享内存
  char * addr = shmat(shmid, NULL, 0);
  sleep(2);
  int count = 0;
  while(count++ < 26)
  {
    printf("client#%s\n",addr);
    sleep(1);
  }
  //取消共享内存
  shmdt(addr);
  sleep(5);
  //删除
  shmctl(shmid,IPC_RMID,NULL);
  return 0;
}
