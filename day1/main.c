#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)

#if 0
//1.���������������в�ͬλ�ĸ���
int calc_dif_bit(int m, int n)
{

	//����1
	//unsigned int tmp = m^n;
	//int count = 0;
	//while (tmp)
	//{
	//	if (tmp & 1)
	//	{
	//		count++;
	//	}
	//	tmp >>= 1;
	//	
	//}

	//����2
	int tmp = m^n;
	int count = 0;
	while (tmp)
	{
		tmp = tmp&(tmp - 1);
		count++;
	}

	return count;
	
}

int main()
{
	int m = 0;
	int n = 0;
	while (scanf("%d %d", &m, &n) == 2)
	{
		int sum = calc_dif_bit(m, n);
		printf("%d\n", sum);
	}
	

	system("pause");
	return 0;
}
#endif

#if 0
//2.��ӡ���������Ƶ�����λ��ż��λ
void PrintBit(int num)
{
	printf("����λ��");
	for (int i = 31; i >= 1; i-=2)
	{
		printf("%d ", (num >> i) & 1);
	}
	printf("\n");
	
	printf("ż��λ�� ");
	for (int i = 30; i >= 0; i-=2)
	{
		printf("%d ", (num >> i) & 1);
	}
	printf("\n");
}

int main()
{
	int num = 0;
	scanf("%d", &num);
	PrintBit(num);

	system("pause");
	return 0;
}
#endif

#if 0
//3.ͳ�ƶ�������1�ĸ���
int CalcBit(int num)
{
	//����1
	unsigned int tmp = num;
	int count = 0;
	while (tmp)
	{
		if (tmp & 1)
		{
			count++;
		}
		tmp >>= 1;
	}

	////����2
	//int count = 0;
	//while (num)
	//{
	//	num = num&(num - 1);
	//	count++;
	//}

	return count;
}

int main()
{
	int num = 0;
	while (scanf("%d", &num) == 1)
	{
		printf("%d��1",CalcBit(num));
	}

	system("pause");
	return 0;
}
#endif


#if 0
//4.����������������������ʱ������

int main()
{
	int a = 10;
	int b = 20;
	printf("����ǰ:a = %d b = %d\n", a, b);
	a = a^b;
	b = a^b;
	a = a^b;
	printf("������:a = %d b = %d\n", a, b);
	return 0;
}
#endif

int main()
{
	int money = 0;
	scanf("%d", &money);
	
	int total = money;
	int empty = money;
	while (empty > 1)
	{

		total += empty/2;
		empty =empty/2+empty%2;
	}

	printf("%d\n", total);
	return 0;

}