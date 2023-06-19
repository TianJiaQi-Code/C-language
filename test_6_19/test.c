#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int Add(int x, int y)
{
	return x + y;
}

int main()
{
	int x, y;
	scanf("%d %d", &x, &y);
	int sum = Add(x, y);
	printf("%d", sum);
	return 0;
}