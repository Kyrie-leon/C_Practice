#include<iostream>
using namespace std;

int main()
{
  int a = 10;
  int& b = a; //1.引用在定义时必须初始化
//int& b;     //没有初始化就会报错

  int c = 20;
  int& rc = c;  //2.一个变量可以有多个引用
  int& rrc = c;
  int& rrrc = c;

  int d = 30;
  int& e = d;
//e = c;    // 3.引用一旦引用一个实体，再不能引用其他实体

  return 0;
}
