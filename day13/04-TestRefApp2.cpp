#include<iostream>
using namespace std;

int& Count()
{
  int n = 0;
  ++n;

  return n;
}

int main()
{
  int ret = Count();
  cout<<ret<<endl;
  return 0;
}


