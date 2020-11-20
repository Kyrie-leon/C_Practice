#include <stdio.h>
#include<Windows.h>
#include<string.h>


#if 0
//1.qsort模拟实现
//模仿qsort的功能实现一个通用的冒泡排序

//定义比较函数
int compar(const void* _px, const void *_py)
{
	//首先对传入的参数进行强制类型转换，转为整形指针类型
	int *px = (int *)_px;
	int *py = (int *)_py;

	//比较两个数的大小，
	//1.升序：若x>y,返回1，x<y,返回-1，x=y，返回0
	if (*px > *py)
	{
		return 1;
	}
	else if (*px < *py)
	{
		return -1;
	}
	else
	{
		return 0;
	}

	//2.降序：若x<y,返回1，x>y,返回-1，x=y，返回0
	//if (*px < *py)
	//{
	//	return 1;
	//}
	//else if (*px > *py)
	//{
	//	return -1;
	//}
	//else
	//{
	//	return 0;
	//}

}

void swap(char *str, char *dst, int size)
{
	//逐个字节交换
	while (size)
	{
		char temp = *str;
		*str = *dst;
		*dst = temp;
		str++;
		dst++;
		size--;
	}
}

//1.模拟qsort实现-冒泡排序
void qsort_bubble(void *base, int num, int size, int(*compar)(const void*, const void*))
{

	//首先判断指针合法性
	assert(base != NULL);
	assert(compar != NULL);

	//将void *base类型变量进行强制类型转换，转为char*类型，方便按字节操作
	char *p = (char *)base;

	//外层循环排num-1趟，内层循环每一趟比较num-1-i次
	for (int i = 0; i<num - 1; i++)
		for (int j = 0; j < num - 1 - i; j++)
		{
			//比较大小
			if (compar(p + j*size, p + (j + 1)*size)>0)
			{
				//定义swap函数用于交换数据
				swap(p + j*size, p + (j + 1)*size, size);

			}
		}

}

//定义一个打印整形数组的函数
void print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int arr1[] = { 1,2,7,432,87,32,879,234,536 };
	int arr2[] = { 1,2,7,432,87,32,879,234,536 };
	int n = sizeof(arr1) / sizeof(arr1[0]);


	//1.先学会使用qsort函数
	print(arr1, n);
	qsort(arr1, n, sizeof(int), compar);
	print(arr1, n);

	//2.自定义冒泡排序qsort_bubble函数
	print(arr2, n);
	qsort_bubble(arr2, n, sizeof(int), compar);
	print(arr2, n);

	system("pause");
	return 0;
}

#endif


//2.使用库函数，qsort排序各种类型的数据
void print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}



// 定义整形比较函数
int compar1(const void* _px, const void *_py)
{
	//首先对传入的参数进行强制类型转换，转为整形指针类型
	int *px = (int *)_px;
	int *py = (int *)_py;

	//比较两个数的大小，
	//1.升序：若x>y,返回1，x<y,返回-1，x=y，返回0
	if (*px > *py)
	{
		return 1;
	}
	else if (*px < *py)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}
//

//2.定义字符串比较
int compar2(const void*_px, const void*_py)
{

	char *px = *(char **)_px;
	char *py = *(char **)_py;
	return strcmp(px, py);

}

//3.字符型比较
int com_char(const void*_px, const void*_py)
{
	char *px = (char *)_px;
	char *py = (char *)_py;
	return *px - *py;
}



int main()
{

	char *str[] = { "abcdfd","daxdasads","abdcsa","ascdasd" };
	int arr1[] = { 1,2,7,432,87,32,879,234,536 };
	int n = sizeof(arr1) / sizeof(arr1[0]);

	//1.整形
	print(arr1, n);
	qsort(arr1, n, sizeof(int), compar1);
	print(arr1, n);

	//2.字符串型
	qsort(str, sizeof(str) / sizeof(str[0]), sizeof(str[0]), compar2);
	for(int i=0;i<sizeof(str) / sizeof(str[0]);i++)
		printf("%s ", str[i]);
	printf("\n");
	//3.字符型比较
	char str1[] = { 'c','a','u','w','g','k' };
	qsort(str1, sizeof(str1) / sizeof(str1[0]), sizeof(char), com_char);
	for (int i = 0; i<sizeof(str1) / sizeof(str1[0]); i++)
		printf("%c ", str1[i]);
	printf("\n");
	//print(*str, sizeof(str) / sizeof(str[0]));
	system("pause");
	return 0;
}

