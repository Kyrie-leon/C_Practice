#include"RingQueue.hpp"

pthread_mutex_t pro_lock; //生产者组内竞争锁
pthread_mutex_t con_lock; //消费者组内竞争锁

int count = 0;

void Lock(pthread_mutex_t &lock)
{
  pthread_mutex_lock(&lock);
}

void UnLock(pthread_mutex_t &unlock)
{
  pthread_mutex_unlock(&unlock);
}

//消费者取数据
void *Get(void *arg)
{
  RingQueue *rq = (RingQueue *)arg;
  while(true)
  {
    usleep(1);
    int data = 0;
    Lock(con_lock); //组内竞争
    rq->Get(data);
    UnLock(con_lock);
    std::cout << pthread_self() <<"consumer done..." << data << std::endl;
  }
}

//生产者生产数据
void *Put(void *arg)
{
  RingQueue *rq = (RingQueue *)arg;
  while(true)
  {
    sleep(1);
    Lock(pro_lock); //组内竞争
    rq->Put(count);
    UnLock(pro_lock);
    std::cout << pthread_self() <<"Productor done.." << count << std::endl;
    count++;
    if(count > 10){
      count = 0;
    }
  }
}
int main()
{
  pthread_t c1, c2, c3, p1, p2, p3;
  RingQueue *rq = new RingQueue();
  //初始化锁
  pthread_mutex_init(&con_lock,nullptr);
  pthread_mutex_init(&pro_lock,nullptr);
  //创建线程
  pthread_create(&c1, nullptr, Get,rq);
  pthread_create(&c2, nullptr, Get,rq);
  pthread_create(&c3, nullptr, Get,rq);
  pthread_create(&p1,nullptr, Put, rq);
  pthread_create(&p2,nullptr, Put, rq);
  pthread_create(&p3,nullptr, Put, rq);

  //等待线程
  pthread_join(c1,nullptr);
  pthread_join(c2,nullptr);
  pthread_join(c3,nullptr);
  pthread_join(p1,nullptr);
  pthread_join(p2,nullptr);
  pthread_join(p3,nullptr);
  //销毁锁清空资源
  pthread_mutex_destroy(&con_lock);
  pthread_mutex_destroy(&pro_lock);
  delete rq;
  return 0;
}
