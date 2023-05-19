#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//1,1,2,3,5,8,13,21...

int Fibonacci(int n)
{
	//���ƹ�ʽ��
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

	//�ǵݹ�
	int i = 0;
	int fib[100] = { 0,1,1 };
	//               0,1,2...
	for (i = 3; i <= n; i++)
	{
		fib[i] = fib[i - 1] + fib[i - 2];
	}
	printf("�ǵݹ飺%d\n", fib[n]);

	//�ݹ�
	int ret = Fibonacci(n);
	printf("�ݹ飺%d\n", ret);
	return 0;
}