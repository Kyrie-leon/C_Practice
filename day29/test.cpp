#include<iostream>
#include<Windows.h>
using namespace std;

////多态原理
//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Base::Func1()" << endl;
//	}
//private:
//	int _b = 1;
//};
//
//int main()
//{
//	Base b1;
//	Base b2;
//	return 0;
//}

//// 针对上面的代码我们做出以下改造
//// 1.我们增加一个派生类Derive去继承Base
//// 2.Derive中重写Func1
//// 3.Base再增加一个虚函数Func2和一个普通函数Func3
//class Base
//{
//public:
//	virtual void Func2()
//	{
//		cout << "Base::Func2()" << endl;
//	}
//
//	virtual void Func1()
//	{
//		cout << "Base::Func1()" << endl;
//	}
//
//	void Func3()
//	{
//		cout << "Base::Func3()" << endl;
//	}
//private:
//	int _b = 1;
//};
//class Derive : public Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Derive::Func1()" << endl;
//	}
//	virtual void Func2()
//	{
//		cout << "Derive::Func2()" << endl;
//	}
//private:
//	int _d = 2;
//};
//
//int main()
//{
//	Base b;
//	Derive d;
//	return 0;
//}


////Q1：虚函数存在哪的？虚表存在哪的？虚表指针存在哪的？
//class Base
//{
//public:
//	virtual void Func2()
//	{
//		cout << "Base::Func2()" << endl;
//	}
//
//	virtual void Func1()
//	{
//		cout << "Base::Func1()" << endl;
//	}
//
//	void Func3()
//	{
//		cout << "Base::Func3()" << endl;
//	}
//private:
//	int _b = 1;
//};
//class Derive : public Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Derive::Func1()" << endl;
//	}
//	virtual void Func2()
//	{
//		cout << "Derive::Func2()" << endl;
//	}
//private:
//	int _d = 2;
//};
//int b;
//
//int main()
//{
//	char *str = "abcd";
//	int *p = new int;
//	const int a = 0;
//	static int c = 1;
//	Base b;
//	Derive d;
//	printf("虚表指针地址:%p\n", (int*)&b);
//	printf("虚表:%p\n", *((int*)&b));
//	printf("堆地址:%p\n", p);
//	printf("栈地址:%p\n", &str);
//	printf("代码段地址:%p\n", str);
//	printf("静态常量区:%p\n", &c);
//	printf("只读常量:%p\n", &a);
//	printf("未初始化数据区:%p\n", &b);
//
//
//	return 0;
//}

//
////多态原理
//class Person {
//public:
//	virtual void BuyTicket() { cout << "买票-全价" << endl; }
//};
//
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "买票-半价" << endl; }
//};
//void Func(Person& p)
//{
//	p.BuyTicket();
//}
//int main()
//{
//	Person Mike;
//	Mike.BuyTicket();
//	Student Johnson;
//	Johnson.BuyTicket();
//	Person Tom=Johnson;
//	Tom.BuyTicket();
//	Func(Mike);
//	Func(Johnson);
//	return 0;
//}

//5.单继承
class Base {
public:
	virtual void func1() { cout << "Base::func1" << endl; }
	   virtual void func2() { cout << "Base::func2" << endl; }
private:
	int a;
};
class Derive :public Base {
public:
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func3() { cout << "Derive::func3" << endl; }
	virtual void func4() { cout << "Derive::func4" << endl; }
private:
	int b;
};

typedef void(*VFPTR) ();
void PrintVTable(VFPTR vTable[])
{
	// 依次取虚表中的虚函数指针打印并调用。调用就可以看出存的是哪个函数
	cout << " 虚表地址>" << vTable << endl;
	for (int i = 0; vTable[i] != nullptr; ++i)
	{
		printf(" 第%d个虚函数地址 :0X%x,->", i, vTable[i]);
		VFPTR f = vTable[i];
		f();
	}
	cout << endl;
}

int main()
{
	Base b;
	Derive d;
	// 思路：取出b、d对象的头4bytes，就是虚表的指针，前面我们说了虚函数表本质是一个存虚函数指针的指针数组，这个数组最后面放了一个nullptr
		// 1.先取b的地址，强转成一个int*的指针
		// 2.再解引用取值，就取到了b对象头4bytes的值，这个值就是指向虚表的指针
		// 3.再强转成VFPTR*，因为虚表就是一个存VFPTR类型(虚函数指针类型)的数组。
		// 4.虚表指针传递给PrintVTable进行打印虚表
		// 5.需要说明的是这个打印虚表的代码经常会崩溃，因为编译器有时对虚表的处理不干净，虚表最后面没有
		//放nullptr，导致越界，这是编译器的问题。我们只需要点目录栏的 - 生成 - 清理解决方案，再编译就好了。
	VFPTR* vTableb = (VFPTR*)(*(int*)&b);
	PrintVTable(vTableb);
	VFPTR* vTabled = (VFPTR*)(*(int*)&d);
	PrintVTable(vTabled);
	return 0;
}