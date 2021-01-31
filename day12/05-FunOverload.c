#include<stdio.h>

int Add(int left ,int right)
{
  return left+right; 
}
 
 
int main()
{
  Add(10, 20);
  Add(10.0, 20.0);
  Add(10L, 20L);

  return 0;

}
