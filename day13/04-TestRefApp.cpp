#include<iostream>
using namespace std;
#if 0
void Swap(int& x, int& y)
{
  int tmp = x;
  x = y;
  y = tmp;
}


int main()
{
  int x1 = 10;
  int y1 = 20;
  cout<<"x1 = "<<x1<<" "<<"y1 = "<<y1<<endl;
  Swap(x1,y1);
  cout<<"x1 = "<<x1<<" "<<"y1 = "<<y1<<endl;
  return 0;
}
#endif


int& Count()
{
  static int n = 0;
  ++n;

  return n;
}

int main()
{
  int ret = Count();
  cout<<ret<<endl;
  return 0;
}


