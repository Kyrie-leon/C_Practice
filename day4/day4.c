#include <stdio.h>
#include<Windows.h>
#include<string.h>


#if 0
//1.qsortģ��ʵ��
//ģ��qsort�Ĺ���ʵ��һ��ͨ�õ�ð������

//����ȽϺ���
int compar(const void* _px, const void *_py)
{
	//���ȶԴ���Ĳ�������ǿ������ת����תΪ����ָ������
	int *px = (int *)_px;
	int *py = (int *)_py;

	//�Ƚ��������Ĵ�С��
	//1.������x>y,����1��x<y,����-1��x=y������0
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

	//2.������x<y,����1��x>y,����-1��x=y������0
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
	//����ֽڽ���
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

//1.ģ��qsortʵ��-ð������
void qsort_bubble(void *base, int num, int size, int(*compar)(const void*, const void*))
{

	//�����ж�ָ��Ϸ���
	assert(base != NULL);
	assert(compar != NULL);

	//��void *base���ͱ�������ǿ������ת����תΪchar*���ͣ����㰴�ֽڲ���
	char *p = (char *)base;

	//���ѭ����num-1�ˣ��ڲ�ѭ��ÿһ�˱Ƚ�num-1-i��
	for (int i = 0; i<num - 1; i++)
		for (int j = 0; j < num - 1 - i; j++)
		{
			//�Ƚϴ�С
			if (compar(p + j*size, p + (j + 1)*size)>0)
			{
				//����swap�������ڽ�������
				swap(p + j*size, p + (j + 1)*size, size);

			}
		}

}

//����һ����ӡ��������ĺ���
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


	//1.��ѧ��ʹ��qsort����
	print(arr1, n);
	qsort(arr1, n, sizeof(int), compar);
	print(arr1, n);

	//2.�Զ���ð������qsort_bubble����
	print(arr2, n);
	qsort_bubble(arr2, n, sizeof(int), compar);
	print(arr2, n);

	system("pause");
	return 0;
}

#endif


//2.ʹ�ÿ⺯����qsort����������͵�����
void print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}



// �������αȽϺ���
int compar1(const void* _px, const void *_py)
{
	//���ȶԴ���Ĳ�������ǿ������ת����תΪ����ָ������
	int *px = (int *)_px;
	int *py = (int *)_py;

	//�Ƚ��������Ĵ�С��
	//1.������x>y,����1��x<y,����-1��x=y������0
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

//2.�����ַ����Ƚ�
int compar2(const void*_px, const void*_py)
{

	char *px = *(char **)_px;
	char *py = *(char **)_py;
	return strcmp(px, py);

}

//3.�ַ��ͱȽ�
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

	//1.����
	print(arr1, n);
	qsort(arr1, n, sizeof(int), compar1);
	print(arr1, n);

	//2.�ַ�����
	qsort(str, sizeof(str) / sizeof(str[0]), sizeof(str[0]), compar2);
	for(int i=0;i<sizeof(str) / sizeof(str[0]);i++)
		printf("%s ", str[i]);
	printf("\n");
	//3.�ַ��ͱȽ�
	char str1[] = { 'c','a','u','w','g','k' };
	qsort(str1, sizeof(str1) / sizeof(str1[0]), sizeof(char), com_char);
	for (int i = 0; i<sizeof(str1) / sizeof(str1[0]); i++)
		printf("%c ", str1[i]);
	printf("\n");
	//print(*str, sizeof(str) / sizeof(str[0]));
	system("pause");
	return 0;
}

