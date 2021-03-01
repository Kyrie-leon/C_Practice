#include<iostream>
#include<stdio.h>
using namespace std;

class A1{
public:
  void f1(){};
  private:
  int _a;
};
// 类中仅有成员函数
class A2 {
public:
  void f2() {}
};
// 类中什么都没有---空类
class A3
  {};

int main()
{
  cout<<sizeof(A1)<<endl;
  cout<<sizeof(A2)<<endl;
  cout<<sizeof(A3)<<endl;
  return 0;
}
