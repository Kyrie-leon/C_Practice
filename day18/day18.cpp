#include<iostream>
using namespace std;

#if 0
//1.2.2
class Time
{
public:
	Time(int hour = 1, int minute=1,int second = 1)
		:_hour(hour)
		,_minute(minute)
		,_second(second)
	{
		cout << "Time(int hour = 1, int minute=1,int second = 1)" << endl;
	}
private:
	int _hour;
	int _minute;
	int _second;
};

class Date
{
public:
	//初始化列表写法
	Date(int year=1900, int month=1, int day=1,int hour=1,int minute=1,int second=1)
		:_year(year)
		,_month(month)
		,_day(day)
		,_n(10)
		,_ref(day)
		,_t(hour,minute,second)
	{
		cout << "Date(int year, int month, int day,int hour,int minute,int second)" << endl;

	}

private:
	int _year;
	int _month;
	int _day;

	//定义的时候需要初始化
	int& _ref;	//引用
	const int _n; //const成员变量
	Time _t;	//自定义类型的成员变量
};

void Test1()
{
	Date d1(2021,3,9,2,2,2);
}
#endif

#if 0
//1.2.2
class Time
{
public:
	Time(int hour = 1, int minute = 1, int second = 1)
		:_hour(hour)
		, _minute(minute)
		, _second(second)
	{
		cout << "Time(int hour = 1, int minute=1,int second = 1)" << endl;
	}
private:
	int _hour;
	int _minute;
	int _second;
};
class Date
{
public:
	//不使用初始化列表
	Date(int year = 1900, int month = 1, int day = 1, int hour = 1, int minute = 1, int second = 1)
	{
		_year = year;
		_month = month;
		_day=day;
		Time t(hour, minute, second);
		_t = t;
		cout << "Date(int year, int month, int day,int hour,int minute,int second)" << endl;

	}

private:
	int _year;
	int _month;
	int _day;
	Time _t;	//自定义类型的成员变量
};

void Test1()
{
	Date d1(2021, 3, 9, 0, 0, 0);
}
#endif

#if 0
//1.2.3
class A
{
public:
	A(int a)
		:_a1(a)
		, _a2(_a1)
	{}
	void Print() {
		cout << _a1 << " " << _a2 << endl;
	}
private:
	int _a2;
	int _a1;
};

void Test2()
{
	A aa(1);
	aa.Print();
}

//1.3.1
class B
{
public:
	B(int b = 0)
		:_b(b)
	{
		cout << "B(int b = 0)" << endl;
	}

	//析构函数
	~B()
	{
		cout << "~B()" << endl;
	}
private:
	int _b;
};

//1.3.3
class C 
{
public:
	explicit C(int c)
		:_c(c)
	{
		cout << "explicit C(int c)" << endl;
	}

private:
	int _c;
};

int main()
{
	C cc(2);
	cc = 8;	//编译器会自动生成一个匿名对象，然后用匿名对象对cc对象进行拷贝构造
	return 0;
}
#endif

#if 0
//2.1 实现一个类，计算程序中创建出了多少个类对象。
class A
{
public:
	//构造函数
	A()
	{
		++_scount;
	}
	//拷贝构造函数
	A(const A& a)
	{
		++_scount;
	}
	void Print()
	{
		cout << GetAcount() << endl;
	}

	static int GetAcount()
	{
		
		return _scount;
	}
private:
	static int _scount;
};

//定义初始化在类外
int A::_scount = 0;

void TestA()
{
	cout << A::GetAcount() << endl;
	A aa;
	A bb;
	A cc(bb);
	cc.Print();
	cout << A::GetAcount() << endl;	
	cout << aa.GetAcount() << endl;
}

int main()
{
	TestA();
	return 0;
}
#endif


#if 0
//3.C++11的成员初始化新玩法
class B
{
public:
	B(int b = 0)
		:_b(b)
	{}
	int _b;
};
class A
{
public:
	void Print()
	{
		cout << a << endl;
		cout << b._b << endl;
		cout << p << endl;
	}
private:
	// 非静态成员变量，可以在成员声明时给缺省值。
	int a = 10;
	B b = 20;
	int* p = (int*)malloc(4);
	//静态成员不可以
	static int n;
};
int A::n = 10;

int main()
{
	A a;
	a.Print();
	return 0;
}
#endif

#if 0
//4.1
class Date
{
friend ostream& operator<<(ostream& _cout, const Date& d);
friend istream& operator >> (istream& _cin, Date& d);

public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(month)
		, _day(day)
	{}
	ostream& operator<<(ostream& _cout)
	{
		_cout << _year << "-" << _month << "-" << _day;
		return _cout;
	}
private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day << endl;
	return _cout;
}

istream& operator >> (istream& _cin, Date& d)
{
	_cin >> d._year >> d._month >> d._day;

	return _cin;
}

int main()
{
	Date d(2017, 12, 24);
	cout<<d;
	//Date d1;
	cin >> d;
	cout << d;
	return 0;
}
#endif


class Date; // 前置声明
class Time
{
	friend class Date; // 声明日期类为时间类的友元类，则在日期类中就直接访问Time类中的私有成员变量
public:
	Time(int hour=0, int minute=0, int second=0)
		: _hour(hour)
		, _minute(minute)
		, _second(second)
	{}
private:
	int _hour;
	int _minute;
	int _second;
};

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{}

	void SetTimeOfDate(int hour, int minute, int second)
	{
		// 直接访问时间类私有的成员变量
		_t._hour = hour;
		_t._minute = minute;
		_t._second = second;
	}
private:
	int _year;
	int _month;
	int _day;

	Time _t;
};

int main()
{
	Date d;
	
	return 0;
}

