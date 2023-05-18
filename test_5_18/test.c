#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int soda = 20;
	int new_soda = 0;
	int empties = 20;
	while (empties > 1)
	{
		new_soda = empties / 2;
		soda = soda + new_soda;
		empties = new_soda + empties % 2;
	}
	printf("%d", soda);
	return 0;
}