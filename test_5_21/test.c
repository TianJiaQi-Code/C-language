#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

void Print(int num)
{
	if (num != 0)
	{
		Print(num / 10);
		printf("%d ", num % 10);
	}
}

int main()
{
	int input;
	scanf("%d", &input);
	Print(input);
	return 0;
}

//int factorial(int n)//·ÇµÝ¹é
//{
//	int i, fac = 1;
//	for (i = 1; i <= n; i++)
//	{
//		fac *= i;
//	}
//	return fac;
//}
//
//int recursion_factorial(int n)//µÝ¹é
//{
//	if (n == 1)
//		return 1;
//	else
//		return n * recursion_factorial(n - 1);
//}
//
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int ret1 = factorial(n);
//	printf("%d\n", ret1);
//
//	int ret2 = recursion_factorial(n);
//	printf("%d\n", ret2);
//	return 0;
//}

//int my_strlen(char str[])//·ÇµÝ¹é
//{
//	int i, count = 0;
//	for (i = 0; str[i] != '\0'; i++)
//	{
//		count++;
//	}
//	return count;
//}
//
//int recursion_strlen(char str[])//µÝ¹é
//{
//	if (str[0] == '\0')
//		return 0;
//	else
//		return 1 + recursion_strlen(&str[1]);
//}
//
//int main()
//{
//	char str[] = "abcdef";
//	int ret1 = my_strlen(str);
//	printf("%d\n", ret1);
//	int ret2 = recursion_strlen(str);
//	printf("%d\n", ret2);
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//
//void reverse_string(char* arr)
//{
//	int len = strlen(arr);
//	char tmp = *arr;
//	*arr = *(arr + len - 1);
//
//	*(arr + len - 1) = '\0';
//	if (strlen(arr + 1) >= 2)
//		reverse_string(arr + 1);
//
//	*(arr + len - 1) = tmp;
//}
//
//int main()
//{
//	char arr[] = "abcdef";
//	reverse_string(arr);
//	puts(arr);
//	return 0;
//}

//int DigitSum(int n)
//{
//	//1729 = 1+7+2+9 = 19
//	if (n / 10 == 0)
//		return n;
//	else
//		return n % 10 + DigitSum(n / 10);
//}
//
//int main()
//{
//	int n, ret;
//	scanf("%d", &n);
//	ret = DigitSum(n);
//	printf("%d", ret);
//	return 0;
//}

//int power(int n, int k)
//{
//	if (k == 1)
//		return n;
//	else
//		return n * power(n, k - 1);
//}
//
//int main()
//{
//	int n, k, ret;
//	scanf("%d %d", &n, &k);
//	ret = power(n, k);
//	printf("%d", ret);
//	return 0;
//}