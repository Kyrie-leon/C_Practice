#pragma warning(disable:4996)
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//	char arr[20] = "hello";
//	int ret = strlen(strcat(arr, "bit"));
//	printf("%d\n", ret);
//	return 0;
//}

#include <stdio.h>
int main()
{
	printf("%d", printf("%d", printf("%d", 43)));
	//½á¹ûÊÇÉ¶£¿
	return 0;
}


//6
//#include<stdio.h>
//
//void FirstFun()
//{
//	printf("hello world\n");
//}
//
//void SecondFun()
//{
//	for (int i = 0; i < 3; ++i)
//	{
//		FirstFun();
//	}
//}
//
//int main()
//{
//	SecondFun();
//	return 0;
//}

//4
//#include <stdio.h>
//void Swap1(int x, int y)
//{
//	int tmp = 0;
//	tmp = x;
//	x = y;
//	y = tmp;
//}
//void Swap2(int *px, int *py)
//{
//	int tmp = 0;
//	tmp = *px;
//	*px = *py;
//	*py = tmp;
//}
//int main()
//{
//	int num1 = 1;
//	int num2 = 2;
//	Swap1(num1, num2);
//	printf("Swap1::num1 = %d num2 = %d\n", num1, num2);
//	Swap2(&num1, &num2);
//	printf("Swap2::num1 = %d num2 = %d\n", num1, num2);
//	return 0;
//}

//int get_max(int x, int y)
//{
//	return x > y ? x : y;
//}
//
//int main()
//{
//	int num1 = 2;
//	int num2 = 8;
//	int max = get_max(num1, num2);
//	printf("max = %d\n", max);
//	return 0;
//}