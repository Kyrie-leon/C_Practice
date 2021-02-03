#include<iostream>
#include<stdlib.h>

class Stack
{
public:
    Stack(int capacity = 4)
    {
      _capacity = capacity;
      _a = (int *)malloc(sizeof(Stack)*_capacity);
      _size = 0;
    }
private:
    int* _a;
    int _size;
    int _capacity;
};

int main()
{
  Stack s1;

  return 0;
}
