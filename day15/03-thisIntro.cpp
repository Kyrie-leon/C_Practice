#include<iostream>
using namespace std;

class Date
{
public:
  void Init(int year, int month, int day)
  {
    _year = year;
    _month = month;
    _day = day;
  }

  void Print()
  {
    cout<<_year<<"-"<<_month<<"-"<<_day<<endl;
  }

private:
  int _year;
  int _month;
  int _day;
};

int main()
{
  Date d1,d2;
  d1.Init(2021,3,1);
  d1.Print();
  d2.Init(2021,2,28);
  d2.Print();
  return 0;
}
