#include<iostream>
using namespace std;

int main()
{
  int a = 10;
  int& b = a; //b是a的别名，b是a的引用，注意&符号在这里不是取地址!
  cout<<&a<<endl;
  cout<<"a="<<a<<endl;
  cout<<&b<<endl;
  cout<<"b="<<b<<endl;
  
  b = 20;
  cout<<&a<<endl;
  cout<<"a="<<a<<endl;
  cout<<&b<<endl;
  cout<<"b="<<b<<endl;

  return 0;
}
