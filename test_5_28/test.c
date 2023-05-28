#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int arr[100][100] = { 0 };
	int input, i, j;
	scanf("%d", &input);
	for (i = 0; i < input; i++)
	{
		for (j = 0; j <= i; j++)
		{
			if (j == 0 || i == j)
			{
				arr[i][j] = 1;
			}
		}
	}
	for (i = 2; i < input; i++)
	{
		for (j = 1; j <= i - 1; j++)
		{
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
	}
	for (i = 0; i < input; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}

//日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个嫌疑犯的一个。
//以下为4个嫌疑犯的供词:
//A说：不是我。
//B说：是C。
//C说：是D。
//D说：C在胡说
//已知3个人说了真话，1个人说的是假话。
//现在请根据这些信息，写一个程序来确定到底谁是凶手。

//#include <stdio.h>
//
//int main()
//{
//	char murderer;
//	for (murderer = 'A'; murderer <= 'D'; murderer++)
//	{
//		if (((murderer != 'A') + (murderer == 'C') + (murderer == 'D') + (murderer != 'D')) == 3)
//		{
//			printf("%c是凶手", murderer);
//			break;
//		}
//	}
//	return 0;
//}