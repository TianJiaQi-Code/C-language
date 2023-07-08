#define _CRT_SECURE_NO_WARNINGS 1

//写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串。
//例如：给定s1 = AABCD和s2 = BCDAA，返回1
//给定s1 = abcd和s2 = ACBD，返回0.
//AABCD左旋一个字符得到ABCDA
//AABCD左旋两个字符得到BCDAA
//AABCD右旋一个字符得到DAABC

#include <stdio.h>
#include <string.h>

int Judgement(char s1[], char s2[])
{
	int sz1 = strlen(s1);
	int i;
	for (i = 0; i < sz1 - 1; i++)
	{
		char* p = s1;
		char temp = s1[0];
		while (*(p + 1) != '\0')
		{
			*p = *(p + 1);
			p++;
		}
		*p = temp;
		if (strcmp(s1, s2) == 0)
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	char s1[10];
	printf("请输入第一个字符串:");
	gets(s1);
	char s2[10];
	printf("请输入第二个字符串:");
	gets(s2);
	int ret = Judgement(s1, s2);
	if (ret == 1)
		printf("Yes\n");
	else if (ret == 0)
		printf("No\n");
	return 0;
}

//实现一个函数，可以左旋字符串中的k个字符。
//例如：
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB

//#include <stdio.h>
//
//void Levorotation(char str[], int k)
//{
//	int i;
//	for (i = 0; i < k; i++)
//	{
//		char* p = str;//p = &str[0]
//		char temp = str[0];
//		while (*(p + 1) != '\0')
//		{
//			*p = *(p + 1);
//			p++;
//		}
//		*p = temp;
//	}
//}
//
//int main()
//{
//	char str[10] = "ABCD";
//	int k;
//	printf("请输入要左旋字符的个数：");
//	scanf("%d", &k);
//	Levorotation(str, k);
//	puts(str);
//	return 0;
//}

//int main()
//{
//	int arr[5][5] = { {1,2,3,4,5},
//					  {2,3,4,5,6},
//					  {3,4,5,6,7},
//					  {4,5,6,7,8},
//					  {5,6,7,8,9} };
//	int input;
//	scanf("%d", &input);
//	int flag = 0;
//	int i;
//	for (i = 0; i < 4; i++)
//	{
//		if (arr[i][0] == input)
//		{
//			printf("找到了\n");
//			flag = 1;
//		}
//	}
//	int j;
//	for (j = 0; j < 5; j++)
//	{
//		if (arr[4][j] == input)
//		{
//			printf("找到了\n");
//			flag = 1;
//		}
//	}
//	if (flag == 0)
//	{
//		printf("没找到\n");
//	}
//	return 0;
//}