#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//1,1,2,3,5,8,13,21...

int Fibonacci(int n)
{
	//µÝÍÆ¹«Ê½£º
	//F(0) = 0
	//F(1) = 1
	//F(n) = F(n-1)+F(n-2)
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main()
{
	int n = 0;
	scanf("%d", &n);

	//·ÇµÝ¹é
	int i = 0;
	int fib[100] = { 0,1,1 };
	//               0,1,2...
	for (i = 3; i <= n; i++)
	{
		fib[i] = fib[i - 1] + fib[i - 2];
	}
	printf("·ÇµÝ¹é£º%d\n", fib[n]);

	//µÝ¹é
	int ret = Fibonacci(n);
	printf("µÝ¹é£º%d\n", ret);
	return 0;
}