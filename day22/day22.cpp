#include<string>	//头文件不加.h
#include<iostream>
using namespace std;

void TestString()
{
	string s1;	//构造空的string类对象
	string s2("hello world"); //用C字符串构造string类对象s2
	string s3(10, 'x');		//构造包含10个字符x的string类对象s3
	string s4(s2);		//拷贝构造s2
}

void TestString1()
{
	string s("hello");
	cout << s.size() << endl;	//返回字符串中的有效字符，不包含'\0'
	cout << s.length() << endl;	//等同于size，但是通常不用length求有效字符
	cout << s.capacity() << endl;	//返回空间总大小，同样不包含'\0'
	cout << s << endl;	//string类对象支持cin输入和cout打印

	// 将s中的字符串清空，注意清空时只是将size清0，不改变底层空间的大小
	s.clear();
	cout << s.size() << endl;	
	cout << s.capacity() << endl;

	// 将s中有效字符个数增加到10个，多出位置用'a'进行填充
	// “aaaaaaaaaa”
	s.resize(10, 'a');
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	// 将s中有效字符个数增加到15个，多出位置用缺省值'\0'进行填充
	// "aaaaaaaaaa\0\0\0\0\0"
	// 注意此时s中有效字符个数已经增加到15个
	s.resize(15);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;

	// 将s中有效字符个数缩小到5个
	s.resize(5);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;

}

void TestString3()
{
	string s;
	// 测试reserve是否会改变string中有效元素个数
	s.reserve(100);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	// 测试reserve参数小于string的底层空间大小时，是否会将空间缩小
	s.reserve(50);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
}

// 利用reserve提高插入数据的效率，避免增容带来的开销
void TestPushBack()
{
	string s;
	size_t sz = s.capacity();
	cout << s.capacity() << endl;
	cout << "making s grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		s.push_back('c');
		//查看扩容了几次
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
}

// 利用reserve提高插入数据的效率，避免增容带来的开销
void TestPushBackReserve()
{
	string s;
	s.reserve(100);
	size_t sz = s.capacity();
	cout << s.capacity() << endl;
	cout << "making s grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		s.push_back('c');
		//查看扩容了几次
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
}

void TestString4()
{
	string s1("hello world");
	string s1("hello Bit");
	const string s2("Hello Bit");
	cout << s1 << " " << s2 << endl;
	cout << s1[0] << " " << s2[0] << endl;
	s1[0] = 'H';
	cout << s1 << endl;
	// s2[0] = 'h'; 代码编译失败，因为const类型对象不能修改
}

int main()
{
	TestPushBackReserve();
	return 0;
}