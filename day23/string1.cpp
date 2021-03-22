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


void TestStringOperator1()
{
	string s1("hello world");
	cout << s1 << endl;
	s1[0] = 'H';
	cout << s1 << endl;

	const string s2("hello c++");
	// s2[0] = 'h'; 代码编译失败，因为const类型对象不能修改
}

//迭代器
void TestStringIterator()
{
	string s("hello world");
	//三种遍历方式：
	//以下三种方式除遍历string外还可修改string中的字符
	//第一种使用较多
	//1.for+operator[]
	cout << "for+operator[]" << endl;
	for (size_t i = 0; i < s.size() - 1; ++i)
	{
		cout << s[i];
	}
	cout << endl;
	//2.正向迭代器
	cout << "2.正向迭代器" << endl;
	string::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it;
		++it;
	}
	cout << endl;
	//2.反向迭代器
	cout << "2.反向迭代器"<<endl;
	string::reverse_iterator rit = s.rbegin();
	while (rit != s.rend())
	{
		cout << *rit;
		++rit;
	}
	cout << endl;
	//3.范围for
	cout << "3.范围for" << endl;
	for (auto ch : s)
	{
		cout << ch;
	}

}

void TestStringInsert()
{
	string s("1234");

	s.insert(2, "00000");
	cout << s << endl;
}

//找文件尾
void TestStringFind()
{
	string s = "hello world";
	s.push_back('!');	//字符串后尾插字符
	cout << s << endl;
	s.append("HELLO");	//字符串后追加字符串
	cout << s << endl;
	s += 'W';			//+=追加字符
	cout << s << endl;
	s += "ORLD";		//+=追加字符串
	cout << s << endl;
	s += s;				//追加string对象
	cout << s << endl;


	string file1("string.cpp");
	string file4("string.c.tar.zip");

	//substr第二个参数可以不写，从前往后找
	size_t pos = file1.find('.');
	if (pos != string::npos)
	{
		cout << file1.substr(pos, file1.size() - pos) << endl;
	}

	//rfind从后往前找
	size_t pos4 = file4.rfind('.');
	if (pos4 != string::npos)
	{
		cout << file4.substr(pos4) << endl;
	}

	//分割域名
	string url = "http://cplusplus.com/reference/string/string/find/";
	cout << url << endl;
	size_t pos5 = url.find(':');	//第一个冒号分割http
	if (pos5 != string::npos)
	{
		cout << url.substr(0, pos5) << endl;
	}

	size_t pos6 = url.find('/', pos5 + 3);	//pos5+3:c  pos6:/
	if (pos6 != string::npos)				//分割网址cplusplus.com
	{
		cout << url.substr(pos5 + 3, pos6 - (pos5 + 3)) << endl;
	}

	cout << url.substr(pos6 + 1, string::npos) << endl;
	//删除http
	string copy = url;
	cout << copy.erase(0, pos5 + 3) << endl;

}

void TestingString()
{
	string s1;
	cin >> s1;	//输入运算符，以空格或回车为结束标志
	cout << "s1:"<<s1 << endl;	//输出运算符
	string s2;
	while (getline(cin, s2))	//输入一行字符串，以回车为结束标志
	{
		cout << "s2:"<<s2 << endl;
	}

}

int main()
{

	TestingString();
	//TestStringIterator();
	//TestStringOperator1();

	//TestStringFind();

	//TestStringInsert();
	//TestPushBackReserve();
	return 0;
}