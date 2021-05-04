#include<iostream>
#include<string>
#include<Windows.h>
using namespace std;

#if 0
//1.2
class Person {
public:
	void Print()
	{
		cout << "name:" << _name << endl;
		cout << "age:" << _age << endl;
	}
private:
	string _name = "peter";
	int _age = 18;
};

class Student :public Person
{
protected:
	int _stuid;
};
int main()
{
	Person t;
	Student s;
	t.Print();
	s.Print();
	return 0;
}
#endif

#if 0
class Person
{
protected:
	string _name; // 姓名
	string _sex; // 性别
	int _age; // 年龄
};
class Student : public Person
{
public:
	int _No; // 学号
};
void Test()
{
	Student sobj;
	// 1.子类对象可以赋值给父类对象/指针/引用
	Person pobj = sobj;
	Person* pp = &sobj;
	Person& rp = sobj;
	//2.基类对象不能赋值给派生类对象
	//sobj = pobj;

	//3.基类的指针可以通过强制类型转换赋值给派生类的指针
	pp = &sobj;
	Student* ps1 = (Student*)pp; // 这种情况转换时可以的。
	ps1->_No = 10;
	pp = &pobj;
	Student* ps2 = (Student*)pp; // 这种情况转换时虽然可以，但是会存在越界访问的问题
	ps2->_No = 10;
}
#endif

#if 0
class Person
{
protected:
	string _name = "张三"; // 姓名
	int _num = 123; // 身份证号
};

class Student : public Person
{
public:
	void Print()
	{
		cout << " 姓名:" << _name << endl;
		cout << " 身份证号:" << Person::_num << endl;
		cout << " 学号:" << _num << endl;
	}
protected:
	int _num = 456; // 学号
};
void Test()
{
	Student s1;
	s1.Print();
};
#endif

#if 0
//2
class A
{
public:
	void fun()
	{
		cout << "func()" << endl;
	}
};
class B : public A
{
public:
	void fun(int i)
	{
		A::fun();
		cout << "func(int i)->" << i << endl;
	}
};
void Test()
{
	B b;
	b.fun(10);
};
#endif


#if 0
//4
class Person
{
public:
	Person(const char* name = "peter")
		: _name(name)
	{
		cout << "Person()" << endl;
	}

	~Person()
	{
		cout << "~Person()" << endl;
	}
protected:
	string _name; // 姓名
};
class Student : public Person
{
public:
	Student(const char* name, int num)
		: Person(name)
		, _num(num)
	{
		cout << "Student()" << endl;
	}
	~Student()
	{
		cout << "~Student()" << endl;
	}
protected:
	int _num; //学号
};
void Test()
{
	Student s1("jack", 18);
}
#endif


////5.1
//class Student;
//class Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);
//protected:
//	string _name; // 姓名
//};
//class Student : public Person
//{
//protected:
//	int _stuNum; // 学号
//};
//void Display(const Person& p, const Student& s)
//{
//	cout << p._name << endl;
//	cout << s._stuNum << endl;
//}
//void test()
//{
//	Person p;
//	Student s;
//	Display(p, s);
//}

//5.2
//class Person
//{
//public:
//	Person() { ++_count; }
//protected:
//	string _name; // 姓名
//public:
//	static int _count; // 统计人的个数。
//};
//int Person::_count = 0;
//class Student : public Person
//{
//protected:
//	int _stuNum; // 学号
//};
//
//void TestPerson()
//{
//	Student s1;
//	Student s2;
//	Student s3;
//	cout << " 人数 :" << Person::_count << endl;
//	Student::_count = 0;
//	cout << " 人数 :" << Person::_count << endl;
//}
//

//菱形继承的问题和解决
//class Person
//{
//public:
//	string _name; // 姓名
//};
//
//class Student : virtual public Person
//{
//protected:
//	int _num; //学号
//};
//class Teacher : virtual public Person
//{
//protected:
//	int _id; // 职工编号
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // 主修课程
//};
//void Test()
//{
//	Assistant a;
//	a._name = "peter";
//	a.Student::_name = "xxx";
//	a.Teacher::_name = "yyy";
//}

//菱形继承的原理
class A
{
public:
	int _a;
};
//class B : public A
class B : virtual public A
{
public:
	int _b;
};
//class C : public A
class C : virtual public A
{
public:
	int _c;
};
class D : public B, public C
{
public:
	int _d;
};
void Test()
{
	D d;
	cout << sizeof(d) << endl;
	d.B::_a = 1;
	d.C::_a = 2;
	d._b = 3;
	d._c = 4;
	d._d = 5;
}

int main()
{
	Test();
	system("pause");
	return 0;
}