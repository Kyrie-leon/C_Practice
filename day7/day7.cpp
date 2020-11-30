#include <stdio.h>
#include <assert.h>
#include <windows.h>

//1.模拟实现strcat
char * my_strcat(char *destination, const char * source)
{
	//首先定义一个指针指向destination起始地址，便于操作完成后返回原始字符串的首地址
	char *dest = destination;
	//判断两个字符串是否为空
	assert(destination != NULL);
	assert(source != NULL);

	//第一轮循环让destination指向\0
	while (*destination)
	{
		destination++;
	}
	//第二轮循环将source内容追加给destination
	while ((*destination++ = *source++))
	{
		;
	}
	//返回dest起始地址
	return dest;
}

//2.模拟实现strcmp
int my_strcmp(const char *str1, const char *str2)
{
	//判断指针合法性
	assert(str1 != NULL);
	assert(str2 != NULL);
	//两个字符串分别从第一个字符进行比较
	while ( (*str1++) && (*str2++) )
	{

		if (*str1  > *str2)
		{
			return 1;
		}
		else if (*str1  < *str2)
		{
			return -1;
		}
		else
		{
			continue;
		}
	}
	return 0;
}

//3.模拟实现strcpy
char * my_strcpy(char * destination, const char *source)
{
	//判断指针合法性
	assert(destination!=NULL);
	assert(source!=NULL);

	//先定义一个指针指向destination便于复制后返回首地址
	char *ret = destination;
	//将第二个字符串的每个字符依次复制到destination中
	while ((*destination++ = *source++))
	{
		;
	}
	return ret;
}
 
//4.模拟实现
//4.1计数器
int my_strlen(const char *str)
{
	//定义一个计数器
	int count = 0;
	//循环扫描字符串直到'/0'
	while (*str)
	{
		//计数器+1，字符串指针+1
		count++;
		str++;
	}

	return count;

}

//4.2不创建临时变量计数器，采用递归的方式
int my_strlen2(const char *str)
{

	if (*str == '\0')
	{
		return 0;
	}
	else
	{
		return 1 + my_strlen2(str + 1);
	}
}

//4.3 双指针
//a.第一个指针指向字符串首地址，第二个指针遍历到字符串结束
//b.第二个指针减去第一个指针即为字符串长度
//注意：由于使用双指针，因此形参不能使用const
int my_strlen3(char *str)
{
	//定义指针p用于遍历字符串
	char *p = str;
	//遍历字符串str
	while (*p)
	{
		p++;
	}

	return p - str;
}

int main()
{
	char str1[16] = "abcd";
	char str2[] = "abc";

	//4.3
	int ret3 = my_strlen3(str1);
	printf("%d\n", ret3);

	//4.2
	int ret2 = my_strlen2(str1);
	printf("%d\n", ret2);

	//4.1
	int ret = my_strlen(str1);
	printf("%d\n", ret);

	//my_strcat(str1, str2);
	//int ret = my_strcmp(str1, str2);
	/*int ret = my_strcmp(str1, str2);
	my_strcpy(str1, str2);
	printf("%s\n", str1);
	*///printf("%d\n", ret);

	system("pause");
	return 0;
}