#include<stdlib.h>
#include<iostream>
using namespace std;

int main(int argc, char* argv[], char* env[])
{
  cout<< getenv("PWD") <<endl;
  return 0;
}
