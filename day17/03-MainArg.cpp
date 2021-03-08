#include<iostream>
using namespace std;

int main(int argc, char* argv[], char* env[])
{
  int i = 0;
  for(;i<argc;++i)
  {
    cout<<"argv["<<i<<"]:"<<argv[i]<<endl;
  }
  
  cout<<"---------------------------------"<<endl;

  for(i =0;env[i];++i)
  {
    cout<<"env["<<i<<"]:"<<env[i]<<endl;
  }
}
