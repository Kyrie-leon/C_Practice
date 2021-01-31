#include<stdio.h>
namespace N1
{
  int a;
  int b;
  int add(int x, int y)
  {
    return x + y;
  }
}


namespace N1
{
  int c;
  int d;
  int Mul(int x, int y)
  {
    return x * y;
  }
}

namespace N2
{
  int a = 10;
  int b = 20;
  int Add(int x, int y)
  {
    return x + y;
  }
  namespace N3
  {
    int c = 30;
    int d = 40;
    int Sub(int x ,int y)
    {
      return x - y;
    }
  }
}

using namespace N2;
using namespace N3;
int main()
{
  printf("%d\n", a);
  printf("%d\n", c);
  printf("%d\n", Add(20,30));

  return 0;
}
