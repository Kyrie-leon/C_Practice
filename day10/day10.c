#include<stdio.h>

int main()
{
	int a = 10;

	int *pa = &a;
	printf("%d\n", *pa);
	int **ppa = &pa;

	int b = 20;
	*ppa = &b;		//�ȼ���pa=&b
	printf("%d\n", *pa);
	**ppa = 30;	//	�ȼ���*pa=30 �ȼ���b=30
	printf("%d\n", *pa);
	printf("%d\n", b);

	int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
	printf("%p\n", arr);
	printf("%p\n", &arr[0]);

	int *p = arr;	//ָ�����p��ŵ�������Ԫ�صĵ�ַ
	int arrSize = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < arrSize; i++)
	{
		printf("%d ", p[i]);
		printf("%d ", *(p+i));
		printf("%d ", arr[i]);
		printf("%d \n", *(arr+i));
	}


	////4.2 ָ���ָ��
	//char s[5] = "abcd";
	//char *p = s;
	//while (*p != '\0')
	//	p++;
	//printf("%p\n", p);
	//printf("%p\n", s);
	//printf("%d\n",p - s);

	//2.2ָ�������
	int n = 0x11223344;
	char *pc = (char *)&n;
	int *pi = &n;
	*pc = 0;
	*pi = 0;



	//2.1 ָ������
	/*int n = 10;
	char *pc = (char *)&n;
	int *pi = &n;

    printf("%p\n", &n);
	printf("%p\n", pc);
	printf("%p\n", pc + 1);
	printf("%p\n", pc - 1);
	printf("%p\n", pi);
	printf("%p\n", pi + 1);
	printf("%p\n", pi - 1);
	*///int a = 10;     //�ڴ��п���һ���ڴ� 
	//    int *p = &a;    // ʹ��&������ȡ������a�ĵ�ַ 
//                    // ʹ��a�ĵ�ַ����ڱ���p�У�p����һ��ָ����� 
//    printf("%d\n",p); 
//    printf("%d\n",&a); 

    return 0;

}
