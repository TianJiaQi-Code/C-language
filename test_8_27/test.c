#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int input;
	printf("ÿ���ö����д��룿");
	scanf("%d", &input);
	if (input > 500)
		printf("��offer\n");
	else if (input < 100)
		printf("����\n");
	else
		printf("ʹ������\n");
}