#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

int globalVar = 1;
static int staticGlobalVar = 1;
void Test1()
{
	static int staticVar = 1;
	int localVar = 1;
	int num1[10] = { 1, 2, 3, 4 };
	char char2[] = "abcd";
	char* pChar3 = "abcd";
	int* ptr1 = (int*)malloc(sizeof(int) * 4);
	int* ptr2 = (int*)calloc(4, sizeof(int));
	int* ptr3 = (int*)realloc(ptr2, sizeof(int) * 4);
	free(ptr1);
	free(ptr3);
}

void Test2()
{
	
	int* p1 = (int*)malloc(sizeof(int));
	// 1.malloc/calloc/realloc的区别是什么？
	int* p2 = (int*)calloc(4, sizeof(int));
	int* p3 = (int*)realloc(p2, sizeof(int)*10);
	// 这里需要free(p2)吗？

	free(p1);
	free(p3);

}

//2.2.1
void Test3()
{
	//动态申请一个int类型的空间
	int* ptr4 = new int;

	//动态申请一个int类型的空间并初始化为10
	int* ptr5 = new int(10);

	//动态申请10个int类型的空间
	int* ptr6 = new int[10];

	delete ptr4;
	delete ptr5;
	delete[] ptr6;
}


//2.2.2
class Date
{
private:
	int _year;
	int _month;
	int _day;
public:
	Date(int year = 1900, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		cout << "Date(int yaer = 1900, int month = 1, int day = 1)"<<endl;
	}
	~Date()
	{
		cout << "~Date()" << endl;
	}
};

void Test4()
{
	//申请单个Date类型的空间
	Date* d1 = (Date *)malloc(sizeof(Date));
	//申请10个Date类型的空间
	Date* d2 = (Date *)malloc(sizeof(Date) * 10);
	free(d1);
	free(d2);
	cout << "--------------" << endl;
	//申请单个Date类型的空间
	Date* d3 = new Date;
	//申请10个Date类型的空间
	Date* d4 = new Date[10];
	delete d3;
	delete[] d4;
}

/*
operator new：该函数实际通过malloc来申请空间，当malloc申请空间成功时直接返回；申请空间失败，
尝试执行空间不足应对措施，如果改应对措施用户设置了，则继续申请，否则抛异常。
*/

void *__CRTDECL operator new(size_t size) _THROW1(_STD bad_alloc)
{
	// try to allocate size bytes
	void *p;
	while ((p = malloc(size)) == 0)
		if (_callnewh(size) == 0)
		{
			// report no memory
			// 如果申请内存失败了，这里会抛出bad_alloc 类型异常
			static const std::bad_alloc nomem;
			_RAISE(nomem);
		}
	return (p);
}

/*
operator delete: 该函数最终是通过free来释放空间的
*/

void operator delete(void *pUserData)
{
	_CrtMemBlockHeader * pHead;
	RTCCALLBACK(_RTC_Free_hook, (pUserData, 0));
	if (pUserData == NULL)
		return;
	_mlock(_HEAP_LOCK); /* block other threads */
	__TRY
		/* get a pointer to memory block header */
		pHead = pHdr(pUserData);
	/* verify block type */
	_ASSERTE(_BLOCK_TYPE_IS_VALID(pHead->nBlockUse));
	_free_dbg(pUserData, pHead->nBlockUse);
	__FINALLY
		_munlock(_HEAP_LOCK); /* release other threads */
	__END_TRY_FINALLY
		return;
}
/*
free的实现
*/
#define free(p)	_free_dpg(p, _NORMAL_BLOCK)

int main()
{
	Test4();
	return 0;
}