#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

int main()
{
	char s1[10] = "hello", s2[10] = "boy";
	printf("%d", strlen(strcpy(s1, s2)));
	return 0;
}