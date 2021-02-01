#include<iostream>
using namespace std;

inline int Add(int x, int y)
{
  return x+y;
}

int main()
{
  int ret = 0;
  ret = Add(1,2);
  cout<<ret<<endl;
  return 0;
}
