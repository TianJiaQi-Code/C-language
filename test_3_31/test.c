#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
int main() {
	int a[4][4] = { {1,3,9,8},{24,18,8,3},{10,24,8,40},
	{46,36,9,10} };
	int i, j;
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			if (a[i][j] > a[j][i])
				a[j][i] = a[i][j];
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++)
			if (j >= i)
				printf("%6d", a[i][j]);
			else
				printf("%6d", '_');
		printf("\n");
	}
	return 0;
}

//#include<stdio.h>
//int f(int a) {
//	return a < 0 ? 1 : a > 0 ? -1 : 0;
//}
//int main() {
//	int a = 15;
//	printf("%d", f(a));
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	char triangle[10][10] = { 0 };
//	int i, j;
//
//	for (i = 0; i < 10; i++)
//	{
//		for (j = 0; j <= i; j++)
//		{
//			if (j == 0 || i == j)
//			{
//				triangle[i][j] = 1;
//			}
//			else
//			{
//				triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
//			}
//			printf("%-6d", triangle[i][j]);
//		}
//		printf("\n");
//	}
//
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
//	char str[1000] = "";
//	int m, n;
//	gets(str);
//	//scanf("%s", str);
//	scanf("%d %d", &m, &n);
//
//	char ret[1000] = "";
//	strncpy(ret, &str[m - 1], n);
//
//	printf("%s", ret);
//
//	return 0;
//}

//int main()
//{
//	double father, mother, child;
//	scanf("%lf %lf", &father, &mother);
//	child = 59.699 + 0.419 * father + 0.265 * mother;
//	printf("%lf", child);
//	return 0;
//}

//int main()
//{
//	// 这是一个C语言中的字符串，而c_str的类型为char，是字符型
//	char* c_str = "hello string";
//
//	// 这是一个C++中的字符串，cpp_str的类型为string，这个才叫字符串型
//	//string cpp_str = "hello string";
//
//	return 0;
//}

//void func(int x)
//{
//    printf("%d", x);
//}

//int main()
//{
//    int a = 1, b = 2;
//
//    int x = (int)(a + b);
//    int y = (int)a + b;
//    //int a = 5 / 3;
//    //int b = 5.0 / 3;
//
//    //printf("%d,%d", a, b);
//    return 0;
//}