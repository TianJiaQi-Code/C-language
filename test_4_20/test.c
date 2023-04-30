#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

void find_two_largest(int a[], int n, int* largest, int* secondlargest)
{
	int i;
	*largest = 0;
	*secondlargest = 0;
	for (i = 0; i < n; i++)
		if (*largest < a[i])
			*largest = a[i];
	for (i = 0; i < n; i++)
		if (*secondlargest < a[i] && a[i] != *largest)
			*secondlargest = a[i];
}

int main()
{
	int a[10] = { 90,10,30,50,40,60,100,20,80,70 };
	int lar, sec;
	find_two_largest(a, 10, &lar, &sec);
	printf("最大值:%d,第二值:%d", lar, sec);
	return 0;
}

//int main()
//{
//	int a[100], n, i, count = 0;
//	scanf("%d", &n);
//	for (i = 0; i < n; i++)
//		scanf("%d", &a[i]);
//	for (i = 1; i < n - 1; i++)
//	{
//		if ((a[i - 1] > a[i] && a[i + 1] > a[i]) || (a[i - 1] < a[i] && a[i + 1] < a[i]))
//			count++;
//	}
//	printf("有%d个折点", count);
//	return 0;
//}

//struct student
//{
//	int num;
//	char name[20];
//	char sex;
//	float score;
//}stu[10] = { 202101,"郭靖",'F',85,202102,"黄蓉",'M',92,202103,"穆念慈",'F',90 };
//
//int main()
//{
//	int i;
//	for (i = 0; i < 3; i++)
//	{
//		printf("%d %s %c %f\n", stu[i].num, stu[i].name, stu[i].sex, stu[i].score);
//	}
//	return 0;
//}

//int main()
//{
//	int x = 1, y = 0, n;
//	n = x-- > (y + x) ? 10 : 12.5 > y++ ? 'A' : 'Z';
//	printf("%c,%d", n, n);
//	return 0;
//}