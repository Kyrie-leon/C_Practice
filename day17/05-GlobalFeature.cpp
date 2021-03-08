#include<stdlib.h>
#include<iostream>
using namespace std;

int main(int argc, char* argv[], char* env[])
{
  cout<< getenv("MYENV") <<endl;
  return 0;
}
