#define _CRT_SECURE_NO_WARNINGS 1

#define ROW 13//菱形的行数

#include <stdio.h>

int main()
{
	int i, j, upper, lower;
	if (ROW % 2 == 0)
		upper = ROW / 2;
	else
		upper = ROW / 2 + 1;
	//upper = 7
	for (i = 0; i < upper; i++)
	{
		for (j = 0; j < upper - i - 1; j++)
		{
			printf(" ");
		}
		for (j = 0; j < i * 2 + 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	lower = upper - 1;
	//lower = 6
	for (i = 0; i < lower; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf(" ");
		}
		for (j = 0; j < 2 * lower -1 - 2 * i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}

//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
//    char str[10000];
//    int left, right, len;
//    gets(str);
//    len = strlen(str);
//    left = 0;
//    right = len - 1;
//    while (left < right)
//    {
//        int temp = str[left];
//        str[left] = str[right];
//        str[right] = temp;
//        left++;
//        right--;
//    }
//    puts(str);
//    return 0;
//}