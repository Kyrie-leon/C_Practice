#include<iostream>
#include<Windows.h>
using namespace std;

////1.2多态的定义和使用
//class Person
//{
//public:
//	//BuyTicket()被virtual关键字修饰，就被称为虚函数
//	virtual void BuyTicket()
//	{
//		cout << "全价买票" << endl;
//	}
//};
//
//class Student : public Person
//{
//public:
//	/*virtual void BuyTicket()
//	{
//		cout << "半价买票" << endl;
//	}*/
//	void BuyTicket()	
//	{
//		cout << "半价买票" << endl;
//	}
//};
//
//// 多态的条件-》满多态，指向谁调用谁的虚函数
//// 1、继承类中，虚函数的重写 
//// 2、基类指针或者引用去调用这个虚函数
////		重写的条件：
////			a、父子类中的函数都是虚函数
////			b、函数名、参数、返回值都要相同
//void Buy(Person& p)
//{
//	// 不满足多态：跟类型有关，也就是说p是什么类型，就掉的这个类型的成员函数
//	// 满足多态：跟对象有关，也就是指向的是哪个对象，调用就是那个的虚函数
//	p.BuyTicket();
//}

////协变
//class A {};
//class B : public A {};
//class Person {
//public:
//	virtual A* f() 
//	{ 
//		cout << "virtual A* f() " << endl;
//		return new A; 
//	}
//};
//
//class Student : public Person {
//public:
//	virtual B* f() 
//	{ 
//		cout << "virtual B* f() " << endl;
//		return new B; 
//	}
//};
//
//void Fun(Person &p)
//{
//	p.f();
//}

////final关键字
//class Car final
//{
//public:
//	virtual void Drive()  {}
//};
//class Benz :public Car
//{
//public:
//	virtual void Drive() { cout << "Benz-舒适" << endl; }
//};

////override
//class Car {
//public:
//	virtual void Drive(int a) {}
//};
//class Benz :public Car {
//public:
//	virtual void Drive() override { cout << "Benz-舒适" << endl; }
//};

////重写析构函数
//class Person {
//public:
//	~Person() { cout << "~Person()" << endl; }
//};
//class Student : public Person {
//public:
//	virtual ~Student() { cout << "~Student()" << endl; }
//};
//// 只有派生类Student的析构函数重写了Person的析构函数，
////下面的delete对象调用析构函数，才能
////构成多态，才能保证p1和p2指向的对象正确的调用析构函数。
//int main()
//{
//	Person* p1 = new Person;
//	Person* p2 = new Student;
//	delete p1;
//	delete p2;
//	system("pause");
//	return 0;
//}
//
////析构函数重写
//class Person {
//public:
//	~Person() { cout << "~Person()" << endl; }
//};
//class Student : public Person {
//public:
//	~Student() { cout << "~Student()" << endl; }
//};
//// 只有派生类Student的析构函数重写了Person的析构函数，下面的delete对象调用析构函数，才能
////构成多态，才能保证p1和p2指向的对象正确的调用析构函数。
//int main()
//{
//	Person* p1 = new Person;
//	Person* p2 = new Student;
//	delete p1;
//	delete p2;
//	system("pause");
//	return 0;
//}

////纯虚函数
//class Car
//{
//public:
//	virtual void Drive() = 0;
//};
//class Benz :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "Benz-舒适" << endl;
//	}
//};
//class BMW :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "BMW-操控" << endl;
//	}
//};
//void Test()
//{
//	Car* pBenz = new Benz;
//	pBenz->Drive();
//	Car* pBMW = new BMW;
//	pBMW->Drive();
//}


class Base
{
public:
	virtual void Func1()
	{
		cout << "Base::Func1()" << endl;
	}
	virtual void Func2()
	{
		cout << "Base::Func2()" << endl;
	}
	void Func3()
	{
		cout << "Base::Func3()" << endl;
	}
private:
	int _b = 1;
};

int main()
{
	Base b;
	cout << sizeof(b) << endl;
	system("pause");
	return 0;
}
