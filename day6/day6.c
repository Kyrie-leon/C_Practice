#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include<errno.h>
#pragma warning(disable:4996)


#if 0
char *GetMemory(void)
{
	char p[] = "hello world";
	return p;
}

int main()
{
	//笔试题2
	
	char *str = NULL;
	str = GetMemory();
	printf(str);

	////3.realloc测试
	//int *ptr = malloc(100);
	//if (ptr != NULL)
	//{
	//	//业务处理
	//}
	//else
	//{
	//	exit(EXIT_FAILURE);
	//}
	////扩展容量
	////代码1
	//ptr = realloc(ptr, 1000);//这样可以吗？(如果申请失败会如何？)

	//						 //代码2
	//int*p = NULL;
	//p = realloc(ptr, 1000);
	//if (p != NULL)
	//{
	//	ptr = p;
	//}
	////业务处理
	//free(ptr);

	////2.calloc测试
	//int *p = (int *)calloc(10, sizeof(int));
	//if (NULL != p)
	//{
	//	printf("success!\n");
	//}

	//free(p);
	//p = NULL;


	////1.malloc测试
	////申请5个整形字节的动态内存
	//int *p = (int *)malloc(5*sizeof(int));
	////若返回值为空，则申请失败
	//if (NULL == p)
	//{
	//	printf("malloc error!\n");
	//	return 1;
	//}
	////若申请成功，为每个元素赋值
	//for (int i = 0; i < 5; i++)
	//{
	//	p[i] = i;
	//}
	//printf("malloc success!\n");

	////打印释放前p的地址
	//printf("before:%p\n",p);
	//
	////释放动态开辟的内存
	//free(p);
	//
	////打印释放后p的地址
	//printf("after:%p\n", p);
	//p = NULL;

	system("pause");
	return 0;
}
#endif


#if 0
//1.字符串旋转结果
/***************************************************************
写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串。
例如：给定s1 =AABCD和s2 = BCDAA，返回1
给定s1=abcd和s2=ACBD，返回0.
AABCD左旋一个字符得到ABCDA
AABCD左旋两个字符得到BCDAA
AABCD右旋一个字符得到DAABC
*******************************************************************/
//思路：其实ABCDE无论怎么旋，旋转后的所有结果，都包含在了ABCDEABCDE这个字符串里了。


int IsStrRot(char *str1, const char *str2)
{
	//定义一个初始变量用于存放两倍原始字符串
	char tmp[256] = { 0 };
	//先拷贝一次原字符串，再追加一次原字符串，这样就可以做到两倍字符串了
	strcpy(tmp, str1);
	strcat(tmp, str1);

	//使用strstr函数查找字符串str2是否是2倍原字符串的子集，如果是返回1，不是返回0
	if (strstr(tmp, str2))
	{
		return 1;
	}
	return 0;
}

int main()
{
	char s1[] = { "abcd" };
	char s2[] = { "ABCD" };
	int ret = IsStrRot(s1, s2);
	printf("result:%d\n", ret);
	system("pause");
	return 0;

}
#endif

#if 0
//2.字符串左旋
/****************************************
实现一个函数，可以左旋字符串中的k个字符。
例如：
ABCD左旋一个字符得到BCDA
ABCD左旋两个字符得到CDAB
*****************************************/
//思路:无论怎么旋转都不会超出ABCDEABCDE，
//因此定义一个临时变量tmp存放该字符串，左旋k个字符等于从位置k开始打印直到k+5停止
//同时5
void LeftTurnStr(char *str, int k)
{
	char tmp[256] = { 0 };
	strcpy(tmp, str);	//拷贝一次
	strcat(tmp, str);	//追加一次

	int len = strlen(str);	
	k %= len; ////长度为5的情况下，旋转6、11、16...次相当于1次，7、12、17...次相当于2次，以此类推。
	for (int i=k,j=0; i < len+k; i++,j++)
	{
		str[j] = tmp[i];
	}
}


int main()
{
	char str[] = { "ABCDE" };
	int k = 11;
	LeftTurnStr(str, k);
	printf("%s\n", str);
	system("pause");
	return 0;
}
#endif

//3.杨氏矩阵
/**************************************************
有一个数字矩阵，矩阵的每行从左到右是递增的，
矩阵从上到下是递增的，请编写程序在这样的矩阵
中查找某个数字是否存在。
要求：时间复杂度小于O(N);
****************************************************/
/*思路：由于杨氏矩阵的特点决定了针对表中的任一元素，
下方和右方的数据一定大于我，左方和上方的数据一定小于我，
所以查找的时候可以利用这一特点，从右上或者右下角来找。
因为这两个位置的大于小于是有区分度的。例如我选择从右上角找，
那么没有上边和右边，所以下边一定比我大，左边一定比我小，
那么要查找的数字如果比我大，那我就向下，
如果比我小，那我就向左，这样查找的次数只有x+y-1次，
符合题目中要求的O(n)。
*/
int FindNum(int a[][3], int x, int y, int f)
{
	int i = 0, j = x - 1;	//右上角开始遍历
	while (j >= 0 && i < y)
	{
		if (a[i][j] < f)	//比我大就向下
		{
			i++;
		}
		else if (a[i][j] < f)	//比我小就向左
		{
			j--;
		}
		else
		{
			return 1;
		}
	}

	return 0;
}


int main()
{
	int arr[][3] = { {1,3,5},
					 {3,5,7},
					 {5,7,9} };
	int num = 7;
	int ret = FindNum(arr, 3,3,7);
	if (ret)
	{
		printf("It has been found!\n");
	}
	else
	{
		printf("It hasn't been found!\n");
	}
	system("pause");
	return 0;

}
