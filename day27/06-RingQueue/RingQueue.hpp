#pragma once
#include<iostream>
#include<vector>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>
#define NUM 10

class RingQueue
{
  private:
    std::vector<int> v; //循环队列
    int _max_cap;
    sem_t sem_blank; //生产者-关心格子
    sem_t sem_data; //消费者-关心数据

    int c_index;  //消费者下标
    int p_index;  //消费者下标

    void P(sem_t &s)  
    {
      sem_wait(&s);
    }

    void V(sem_t &s)
    {
      sem_post(&s);
    }

  public:
    //构造函数
    RingQueue(int cap = NUM)
      :_max_cap(cap)
    {
      v.resize(cap);
      sem_init(&sem_blank, 0, _max_cap);
      sem_init(&sem_data, 0, 0);
      c_index = 0;
      p_index = 0;
    }
    
    //取数据
    void Get(int &out)
    {
      P(sem_data);
      out = v[c_index];
      c_index++;
      c_index %= _max_cap;
      V(sem_blank);
    }
    
    //放数据
    void Put(const int &in)
    {
      P(sem_blank);
      v[p_index] = in;
      p_index++;
      p_index %= _max_cap;
      V(sem_data);
    }

    ~RingQueue()
    {
      sem_destroy(&sem_blank);
      sem_destroy(&sem_data);
      c_index = p_index = 0;
    }
};
