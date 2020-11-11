#include <stdio.h>
#include <assert.h>

#if 0
//1.代码调试解释问题
int main()
{
	int i = 0;
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	for (i = 0; i <= 12; i++)
	{
		arr[i] = 0;
		printf("hello bit\n");
	}
	return 0;
}
#endif

#if 0
//2.模拟strlen实现
unsigned int strlen(const char *str)
{
	unsigned int count=0;
	while (*str++)
	{
		count++;
	}
	return count;
}

//3.模拟strcpy
char *my_strcpy(char *dst, char *scr)
{
	char *pst = dst;
	assert(dst != NULL);
	assert(scr != NULL);
	while (*dst++ = *scr++)
	{
		;
	}
	return pst;
}
#endif

//4.调整奇数偶数顺序
//题目：
//输入一个整数数组，实现一个函数，
//来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，
//所有偶数位于数组的后半部分。
void Adjust(int arr[], int len)
{
	int tmp = 0;
	int *left = arr;
	int *right = &arr[len - 1];
	while (left < right)
	{
		while (*left % 2 == 1)
		{
			left++;
		}
		while (*right % 2 == 0)
		{
			right--;
		}
		if (left < right)
		{
			tmp = *left;
			*left = *right;
			*right = tmp;
			left++;
			right--;

		}

	}

}


int main()
{

	//4.
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int len = sizeof(arr) / sizeof(arr[0]);
	Adjust(arr, len);
	for (int i = 0; i < len; i++)
	{
		printf("arr[%d]=%d\n", i,arr[i]);
	}



	/*char str1[] = "abcd";
	char str2[] = "qweasd";
	my_strcpy(str1, str2);
	printf("%s\n", str1);*/

	return 0;
}
