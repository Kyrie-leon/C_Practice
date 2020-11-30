#include <stdio.h>
#include <assert.h>
#include <windows.h>

//1.ģ��ʵ��strcat
char * my_strcat(char *destination, const char * source)
{
	//���ȶ���һ��ָ��ָ��destination��ʼ��ַ�����ڲ�����ɺ󷵻�ԭʼ�ַ������׵�ַ
	char *dest = destination;
	//�ж������ַ����Ƿ�Ϊ��
	assert(destination != NULL);
	assert(source != NULL);

	//��һ��ѭ����destinationָ��\0
	while (*destination)
	{
		destination++;
	}
	//�ڶ���ѭ����source����׷�Ӹ�destination
	while ((*destination++ = *source++))
	{
		;
	}
	//����dest��ʼ��ַ
	return dest;
}

//2.ģ��ʵ��strcmp
int my_strcmp(const char *str1, const char *str2)
{
	//�ж�ָ��Ϸ���
	assert(str1 != NULL);
	assert(str2 != NULL);
	//�����ַ����ֱ�ӵ�һ���ַ����бȽ�
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

//3.ģ��ʵ��strcpy
char * my_strcpy(char * destination, const char *source)
{
	//�ж�ָ��Ϸ���
	assert(destination!=NULL);
	assert(source!=NULL);

	//�ȶ���һ��ָ��ָ��destination���ڸ��ƺ󷵻��׵�ַ
	char *ret = destination;
	//���ڶ����ַ�����ÿ���ַ����θ��Ƶ�destination��
	while ((*destination++ = *source++))
	{
		;
	}
	return ret;
}
 
//4.ģ��ʵ��
//4.1������
int my_strlen(const char *str)
{
	//����һ��������
	int count = 0;
	//ѭ��ɨ���ַ���ֱ��'/0'
	while (*str)
	{
		//������+1���ַ���ָ��+1
		count++;
		str++;
	}

	return count;

}

//4.2��������ʱ���������������õݹ�ķ�ʽ
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

//4.3 ˫ָ��
//a.��һ��ָ��ָ���ַ����׵�ַ���ڶ���ָ��������ַ�������
//b.�ڶ���ָ���ȥ��һ��ָ�뼴Ϊ�ַ�������
//ע�⣺����ʹ��˫ָ�룬����ββ���ʹ��const
int my_strlen3(char *str)
{
	//����ָ��p���ڱ����ַ���
	char *p = str;
	//�����ַ���str
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