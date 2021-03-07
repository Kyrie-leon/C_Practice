//#include<iostream>
//#include<windows.h>
//using namespace std;
//
//
//class A
//{
//public:
//	void PrintA()
//	{
//		cout << _a << endl;
//	}
//	void Show()
//	{
//		cout << "Show()" << endl;
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	A* p = NULL;
//	//p->PrintA();
//	p->Show();
//	return 0;
//}

#include<iostream>
using namespace std;

#if 0
//2.2.4
class Date
{
public:
	//1.无参构造函数
	Date()
	{}
	//2.带参构造函数
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

private:
	int _year;
	int _month;
	int _day;
};



void Test1()
{
	Date d1;  //调用无参构造函数
	d1.Print();
	Date d2(2021, 3, 2); //调用带参构造函数
	d2.Print();
	// 注意：如果通过无参构造函数创建对象时，对象后面不用跟括号，否则就成了函数声明
	// 以下代码的函数：声明了d3函数，该函数无参，返回一个日期类型的对象
	Date d3();
	//d3.Print();
}
#endif

#if 0
//2.26
class Date
{
public:
	/*
	// 如果用户显式定义了构造函数，编译器将不再生成
	Date (int year, int month, int day)
	{
	_year = year;
	_month = month;
	_day = day;
	}
	*/
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
void Test2()
{
	// 没有定义构造函数，对象也可以创建成功，因此此处调用的是编译器生成的默认构造函数
	Date d;
	d.Print();
}
#endif

// 2.2 
//6.默认构造函数
//class Date
//{
//public:
//	Date()
//	{
//		_year = 1900;
//		_month = 1;
//		_day = 1;
//	}
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//// 以下测试函数能通过编译吗？
//void Test()
//{
//	Date d1;
//}

#if 0
//2.2.7
class Time
{
public:
	Time()
	{
		cout << "Time()构造函数" << endl;
		_hour = 0;
		_minute = 0;
		_second = 0;
	}
private:
	int _hour;
	int _minute;
	int _second;
};

class Date
{

private:
	//基本内置类型
	int _year;
	int _month;
	int _day;
	//自定义类型
	Time _t;
};

void Test3()
{
	Date d;
}
#endif

#if 0
//3.2.1234
class Stack
{
public:
	Stack(int capacity = 4)
	{
		_a = (int *)malloc(sizeof(int)*capacity);
		_size = 0;
		_capacity = capacity;
	}

	//栈的析构函数
	~Stack()
	{
		free(_a);	//释放堆上的空间
		_a = nullptr;	//指针置空
		_size = _capacity = 0;
		cout << "~Stack()析构函数" << endl;
	}
private:
	int* _a;
	int _size;
	int _capacity;
};

void Test4()
{
	Stack s;
}
#endif

#if 0
//3.2.5
class Stack
{
public:
	Stack(int capacity = 4)
	{
		_a = (int *)malloc(sizeof(int)*capacity);
		_size = 0;
		_capacity = capacity;
	}

	//栈的析构函数
	~Stack()
	{
		free(_a);	//释放堆上的空间
		_a = nullptr;	//指针置空
		_size = _capacity = 0;
		cout << "~Stack()析构函数" << endl;
	}
private:
	int* _a;
	int _size;
	int _capacity;
};

class Person
{
private:
	int _age;
	Stack _s;
};

void Test5()
{
	Person p;
}
#endif

#if 0
//4.2.2
class Date
{
public:
	
	Date(int year=1900, int month=1, int day=1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	//拷贝构造
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

void Test6()
{
	Date d1(2021,3,7);
	Date d2(d1);
	Date d3 = d1;
	d1.Print();
	d2.Print();
	d3.Print();
}
#endif

#if 0
//5.1
class Date
{
public:

	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	//bool operator==(Date* this, const Date& d2)
	//这里需要注意的是，左操作数是this指向的调用函数的对象
	bool operator==(const Date& d2)
	{
		return _year == d2._year
			&& _month == d2._month
			&& _day == d2._day;
	}

	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

void Test7()
{
	Date d1(2021, 3, 7);
	Date d2(2021, 3, 6);
	Date d3(2021, 3, 7);
	cout << (d1 == d2) <<endl;
	cout << (d1 == d3) << endl;
}
#endif

#if 0
//5.2
class Date
{
public:

	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	//如果用户没有显式定义赋值运算符重载，编译器器也会自动生成一个
	bool operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day == d._day;
		}
	}

	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

void Test8()
{
	Date d1(2021, 3, 7);
	Date d2 = d1;
	d1.Print();
	d2.Print();
}
#endif

#if 0
//6.1
class Date
{
public:

	Date(int year = 1900, int month = 1, int day = 1) 
	{
		_year = year;
		_month = month;
		_day = day;

	}

	void Change(int day=1)
	{
		_day = day;
	}

	void Print() const
	{
		Change();
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

void Test8()
{
	const Date d1(2021, 3, 7);
	d1.Print();
}
#endif

//7
class Date
{
public:
	Date* operator&()
	{
		return this;
	}
	const Date* operator&()const
	{
		return this;
	}
private:
	int _year; // 年
	int _month; // 月
	int _day; // 日
};

int main()
{

	Test8();
	return 0;
}
