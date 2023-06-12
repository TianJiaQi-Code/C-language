#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

void menu()
{
	printf("*****************************\n");
	printf("*********  0. exit  *********\n");
	printf("*********  1. play  *********\n");
	printf("*****************************\n");
}

int main()
{
	int input;
	do
	{
		menu();
		scanf("%d", &input);
	} while (input);
	return 0;
}