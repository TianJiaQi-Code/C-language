#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

void main()
{
	int number, rdigit;
	printf("Please input a number:");
	scanf("%d", &number);
	do {
		rdigit = number % 10;
		printf("%d ", rdigit);
		number /= 10;
	} while (number != 0);
}