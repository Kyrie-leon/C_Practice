#include<stdio.h>

int main()
{

	int n = 10;
	char *pc = (char *)&n;
	int *pi = &n;

    printf("%p\n", &n);
	printf("%p\n", pc);
	printf("%p\n", pc + 1);
	printf("%p\n", pc - 1);
	printf("%p\n", pi);
	printf("%p\n", pi + 1);
	printf("%p\n", pi - 1);
  int a = 10;     //�ڴ��п���һ���ڴ� 
//    int *p = &a;    // ʹ��&������ȡ������a�ĵ�ַ 
//                    // ʹ��a�ĵ�ַ����ڱ���p�У�p����һ��ָ����� 
//    printf("%d\n",p); 
//    printf("%d\n",&a); 

    return 0;

}
