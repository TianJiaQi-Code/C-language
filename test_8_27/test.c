#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int input;
	printf("每天敲多少行代码？");
	scanf("%d", &input);
	if (input > 500)
		printf("好offer\n");
	else if (input < 100)
		printf("进厂\n");
	else
		printf("痛苦挣扎\n");
}