#include <iostream>

using namespace std;

void TestFun(int a = 10)
{
  cout<<a<<endl;
}

void TestFun1(int a=10, int b =20, int c=30)
{
  cout<<"a= "<<a<<endl;
  cout<<"b= "<<b<<endl;
  cout<<"c= "<<c<<endl;
}

void TestFun2(int a, int b=20, int c=30)
{
  cout<<"a= "<<a<<endl;
  cout<<"b= "<<b<<endl;
  cout<<"c= "<<c<<endl;
  
}

int main()
{
  TestFun1();
  TestFun1(1);
  TestFun1(1,2);
  TestFun1(1,2,3);

  TestFun2(1);
  TestFun2(1,2);
  TestFun2(1,2,3);

}
