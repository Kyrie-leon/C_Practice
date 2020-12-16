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
  int a = 10;     //内存中开辟一块内存 
//    int *p = &a;    // 使用&操作符取出变量a的地址 
//                    // 使用a的地址存放在变量p中，p就是一个指针变量 
//    printf("%d\n",p); 
//    printf("%d\n",&a); 

    return 0;

}
