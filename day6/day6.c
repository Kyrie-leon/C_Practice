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
	//������2
	
	char *str = NULL;
	str = GetMemory();
	printf(str);

	////3.realloc����
	//int *ptr = malloc(100);
	//if (ptr != NULL)
	//{
	//	//ҵ����
	//}
	//else
	//{
	//	exit(EXIT_FAILURE);
	//}
	////��չ����
	////����1
	//ptr = realloc(ptr, 1000);//����������(�������ʧ�ܻ���Σ�)

	//						 //����2
	//int*p = NULL;
	//p = realloc(ptr, 1000);
	//if (p != NULL)
	//{
	//	ptr = p;
	//}
	////ҵ����
	//free(ptr);

	////2.calloc����
	//int *p = (int *)calloc(10, sizeof(int));
	//if (NULL != p)
	//{
	//	printf("success!\n");
	//}

	//free(p);
	//p = NULL;


	////1.malloc����
	////����5�������ֽڵĶ�̬�ڴ�
	//int *p = (int *)malloc(5*sizeof(int));
	////������ֵΪ�գ�������ʧ��
	//if (NULL == p)
	//{
	//	printf("malloc error!\n");
	//	return 1;
	//}
	////������ɹ���Ϊÿ��Ԫ�ظ�ֵ
	//for (int i = 0; i < 5; i++)
	//{
	//	p[i] = i;
	//}
	//printf("malloc success!\n");

	////��ӡ�ͷ�ǰp�ĵ�ַ
	//printf("before:%p\n",p);
	//
	////�ͷŶ�̬���ٵ��ڴ�
	//free(p);
	//
	////��ӡ�ͷź�p�ĵ�ַ
	//printf("after:%p\n", p);
	//p = NULL;

	system("pause");
	return 0;
}
#endif


#if 0
//1.�ַ�����ת���
/***************************************************************
дһ���������ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
���磺����s1 =AABCD��s2 = BCDAA������1
����s1=abcd��s2=ACBD������0.
AABCD����һ���ַ��õ�ABCDA
AABCD���������ַ��õ�BCDAA
AABCD����һ���ַ��õ�DAABC
*******************************************************************/
//˼·����ʵABCDE������ô������ת������н��������������ABCDEABCDE����ַ������ˡ�


int IsStrRot(char *str1, const char *str2)
{
	//����һ����ʼ�������ڴ������ԭʼ�ַ���
	char tmp[256] = { 0 };
	//�ȿ���һ��ԭ�ַ�������׷��һ��ԭ�ַ����������Ϳ������������ַ�����
	strcpy(tmp, str1);
	strcat(tmp, str1);

	//ʹ��strstr���������ַ���str2�Ƿ���2��ԭ�ַ������Ӽ�������Ƿ���1�����Ƿ���0
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
//2.�ַ�������
/****************************************
ʵ��һ�����������������ַ����е�k���ַ���
���磺
ABCD����һ���ַ��õ�BCDA
ABCD���������ַ��õ�CDAB
*****************************************/
//˼·:������ô��ת�����ᳬ��ABCDEABCDE��
//��˶���һ����ʱ����tmp��Ÿ��ַ���������k���ַ����ڴ�λ��k��ʼ��ӡֱ��k+5ֹͣ
//ͬʱ5
void LeftTurnStr(char *str, int k)
{
	char tmp[256] = { 0 };
	strcpy(tmp, str);	//����һ��
	strcat(tmp, str);	//׷��һ��

	int len = strlen(str);	
	k %= len; ////����Ϊ5������£���ת6��11��16...���൱��1�Σ�7��12��17...���൱��2�Σ��Դ����ơ�
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

//3.���Ͼ���
/**************************************************
��һ�����־��󣬾����ÿ�д������ǵ����ģ�
������ϵ����ǵ����ģ����д�����������ľ���
�в���ĳ�������Ƿ���ڡ�
Ҫ��ʱ�临�Ӷ�С��O(N);
****************************************************/
/*˼·���������Ͼ�����ص��������Ա��е���һԪ�أ�
�·����ҷ�������һ�������ң��󷽺��Ϸ�������һ��С���ң�
���Բ��ҵ�ʱ�����������һ�ص㣬�����ϻ������½����ҡ�
��Ϊ������λ�õĴ���С���������ֶȵġ�������ѡ������Ͻ��ң�
��ôû���ϱߺ��ұߣ������±�һ�����Ҵ����һ������С��
��ôҪ���ҵ�����������Ҵ����Ҿ����£�
�������С�����Ҿ������������ҵĴ���ֻ��x+y-1�Σ�
������Ŀ��Ҫ���O(n)��
*/
int FindNum(int a[][3], int x, int y, int f)
{
	int i = 0, j = x - 1;	//���Ͻǿ�ʼ����
	while (j >= 0 && i < y)
	{
		if (a[i][j] < f)	//���Ҵ������
		{
			i++;
		}
		else if (a[i][j] < f)	//����С������
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
