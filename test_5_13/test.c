#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>

int Is_Prime(int num)
{
	int i;
	for (i = 2; i <= sqrt(num); i++)
	{
		if (num % i == 0)
			return 0;
	}
	return 1;
}

int main()
{
	int i;
	for (i = 100; i <= 200; i++)
	{
		if (Is_Prime(i) == 1)
		{
			printf("%d ", i);
		}
	}
	return 0;
}

//int Is_Leap(int year)
//{
//	return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
//}
//
//int main()
//{
//	int year, ret;
//	scanf("%d", &year);
//	ret = Is_Leap(year);
//	if (ret == 1)
//		printf("是闰年");
//	else
//		printf("不是闰年");
//	return 0;
//}

//void exchange(int* x, int* y)
//{
//	int temp = *x;
//	*x = *y;
//	*y = temp;
//}
//
//int main()
//{
//	int a, b;
//	scanf("%d%d", &a, &b);
//	exchange(&a, &b);
//	printf("%d %d", a, b);
//	return 0;
//}

//void table(int input)
//{
//	int i, j;
//	for (i = 1; i <= input; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("%2d*%2d=%3d ", j, i, i * j);
//		}
//		printf("\n");
//	}
//}
//
//int main()
//{
//	int input;
//	scanf("%d", &input);
//	table(input);
//	return 0;
//}