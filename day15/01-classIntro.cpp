#include<iostream>
using namespace std;

class Person
{
public:
  //显示基本信息
  void showIndo()
  {
    cout<<_name<<"-"<<_sex<<"-"<<_age<<endl;
  }
public:
  char* _name; //姓名
  char* _sex; //性别
  int _age;   //年龄
};

int main()
{
  return 0;
}
