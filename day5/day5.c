#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<errno.h>
#pragma warning(disable:4996)
题目：03 - C语言进阶——字符函数和字符串函数
csdn地址：
https ://blog.csdn.net/qq_40076022/article/details/109893212
int main()
{

	//memset
	int a[5] = { 0 };
	memset(a, 1, sizeof(a));
	for (int i = 0; i < 5; i++)
		printf("a[%d]=%d\n", i, a[i]);

	//memcpy
	/*char buffer1[] = "DWgaOtP12df0";
	char buffer2[] = "DWGAOTP12DF0";

	int n;

	n = memcmp(buffer1, buffer2, sizeof(buffer1));

	if (n>0) printf("'%s' is greater than '%s'.\n", buffer1, buffer2);
	else if (n<0) printf("'%s' is less than '%s'.\n", buffer1, buffer2);
	else printf("'%s' is the same as '%s'.\n", buffer1, buffer2);
*/
	//memcpy拷贝结构体，例如：
	//struct {
	//	char name[16];
	//	int age;
	//}person,person_copy;

	//char myname[] = "kyrie";
	//memcpy(person.name, myname, strlen(myname) + 1);
	//person.age = 46;

	///* using memcpy to copy structure: */
	//memcpy(&person_copy, &person, sizeof(person));

	//printf("person_copy: %s, %d \n", person_copy.name, person_copy.age);

	// 字符转换:将字符串中大写字母转化为小写字母
	/*int i = 0;
	char str[] = "Test String.\n";
	char c;
	while (str[i])
	{
		c = str[i];
		if (isupper(c))
			c = tolower(c);
		putchar(c);
		i++;
	}*/

	/*char c = 'a';
	if (isupper(c))
	{
		printf("c为空格\n");
	}*/

	//// strerror
	//for (int i = 1; i < 50; i++)
	//{
	//	printf("%d->%s\n", i, strerror(i));
	//}

	//strtok
	//char str[] = "- This, a sample string.";
	//char * pch;
	//printf("Splitting string \"%s\" into tokens:\n", str);
	//pch = strtok(str, " ,.-");
	//while (pch != NULL)
	//{
	//	printf("%s\n", pch);
	//	pch = strtok(NULL, " ,.-");
	//}

	//char *p = "kyrieleon@gmail.com";
	//const char* sep = ".@";
	//char arr[30];
	//char *str = NULL;
	//strcpy(arr, p);//将数据拷贝一份，处理arr数组的内容
	//for (str = strtok(arr, sep); str != NULL; str = strtok(NULL, sep))
	//{
	//	printf("%s\n", str);
	//}


	////// strstr
	//char str[] = "This is a simple string.";
	//char *pch;
	//pch = strstr(str, "simple");
	//strncpy(pch, "sample", 6);
	//puts(str);


	// 3.3strncmp 
	//char str[][5] = { "r2d2","b7ud","r2o9" };
	//int n;
	//puts("looking for r2 astromech droids...");
	//for (n = 0; n < 3; n++)
	//{
	//	if (strncmp(str[n], "r2xx", 2) == 0)
	//	{
	//		printf("founds %s\n",str[n]);
	//	}
	//}


	//puts和printf区别
	/*puts("hello world %d\n");
	printf("hello world %d\n", 10);
*/

	//3.3 strncat
	/*char str1[20];
	char str2[20];
	strcpy(str1, "To be ");
	strcpy(str2, "or not to be");
	strncat(str1, str2, 6);
	puts(str1);*/

	//3.1 strncpy
	//char *src = " world!";
	//char dst[16] = "hello";
	//strncpy(dst, src, strlen(src)+1);

	////2.3strcmp
	//const char * str1 = "abc";
	//const char * str2 = "abc";

	//if (strcmp(str1, str2)==0)
	//{
	//	printf("相等\n");
	//}
	//else
	//{
	//	printf("不相等\n");
	//}


	//2.2strcat
	//const char *src = " world!";
	//char dst[16]="hello";
	//strcat(dst, dst);
	//printf("%s\n", dst);


	////2.1 strcpy
	//const char *src = "hello world";
	//char dst[16];
	//strcpy(dst, src);
	//printf("%s\n", dst);

	////1.1 strlen
	//const char*str1 = "abcdef";
	//const char*str2 = "bbb";
	//if (strlen(str2) - strlen(str1)>0)
	//{
	//	printf("str2>str1\n");
	//}
	//else
	//{
	//	printf("srt1>str2\n");
	//}

	system("pause");
	return 0;
}