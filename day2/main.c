#include <stdio.h>
#include <assert.h>

#if 0
//1.������Խ�������
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
//2.ģ��strlenʵ��
unsigned int strlen(const char *str)
{
	unsigned int count=0;
	while (*str++)
	{
		count++;
	}
	return count;
}

//3.ģ��strcpy
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

//4.��������ż��˳��
//��Ŀ��
//����һ���������飬ʵ��һ��������
//�����������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣�
//����ż��λ������ĺ�벿�֡�
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
