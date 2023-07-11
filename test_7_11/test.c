#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

char* my_strstr(char* str1, char* str2)
{
	char* cp = str1;
	char* s1 = cp;
	char* s2 = str2;
	if (*str2 == '\0')
		return str1;
	while (*cp)
	{
		s1 = cp;
		s2 = str2;
		while (*s1 && *s2 && *s1 == *s2)
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')
			return cp;
		cp++;
	}
	return NULL;
}

int main()
{
	char str1[10] = "abcdefg";
	char str2[10] = "cd";
	char* ret = strstr(str1, str2);
	printf("%s\n", ret);
	ret = my_strstr(str1, str2);
	printf("%s\n", ret);
	return 0;
}

//void my_strcat(char* str1, const char* str2)
//{
//	while (*str1 != '\0')
//	{
//		str1++;
//	}
//	while (*str2 != '\0')
//	{
//		*str1 = *str2;
//		str1++;
//		str2++;
//	}
//	*str1 = '\0';
//}
//
//int main()
//{
//	char str1[50] = "hello ";
//	char str2[10] = "world!";
//	strcat(str1, str2);
//	puts(str1);
//	my_strcat(str1, str2);
//	puts(str1);
//	return 0;
//}

//int my_strcmp(const char* str1, const char* str2)
//{
//	while (*str1 == *str2)
//	{
//		if (*str1 == '\0')
//		{
//			return 0;
//		}
//		str1++;
//		str2++;
//	}
//	return *str1 - *str2;
//}
//
//int main()
//{
//	char str1[10] = "abcdef";
//	char str2[10] = "abcde";
//	int ret = strcmp(str1, str2);
//	printf("%d\n", ret);
//	ret = my_strcmp(str1, str2);
//	printf("%d\n", ret);
//	return 0;
//}