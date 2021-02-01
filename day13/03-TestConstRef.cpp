#include<iostream>
using namespace std;

int main()
{
  int a = 10;
  int& ra = a; //1.ra的类型必须和a的类型相同，都为int
//char& c = a;  //c的类型为char，而b的类型为int，类型不同这种初始化方式会报错

  const int b = 20; //const修饰b后，b为常量
//int& c = b;       //2.c是变量，将常量b赋值给变量c会报错，类型不匹配
  const int& c = b; //b,c都是常量，语句正确

  int d = 30;       //d是int类型的变量
  const int cd = 40;//cd时int类型的常量
  const int& e = d; //将变量d赋值给常量e是被允许的
  const int& rd = cd;//常量cd可以赋值给常量rd
  int& f = d;       //变量d赋值给变量f也是被允许的

  return 0;
}
