#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int arr[] = { 1,3,5,7,9,11,13,15,17,19 };
	//            0,1,2,3,4,5 ,6 ,7 ,8 ,9
	int left, right, mid, num, flag = 0;
	scanf("%d", &num);
	left = 0;
	right = sizeof(arr) / sizeof(arr[0]) - 1;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (arr[mid] == num)
		{
			printf("找到了,下标是%d", mid);
			flag = 1;
			break;
		}
		else
		{
			if (arr[mid] > num)
			{
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}
		}
	}
	if (flag == 0)
	{
		printf("找不到");
	}
	return 0;
}

//#include <stdio.h>
//
//int main()
//{
//	int i, sum = 0, num, temp;
//	for (i = 1; i <= 100; i++)
//	{
//		temp = i;
//		while (temp)
//		{
//			num = temp % 10;
//			if (num == 9)
//			{
//				sum++;
//			}
//			temp /= 10;
//		}
//	}
//	printf("%d", sum);
//	return 0;
//}

//int main()
//{
//	int i;
//	double sum = 0, symbol = 1;
//	for (i = 1; i <= 100; i++)
//	{
//		sum += symbol / i;
//		symbol *= -1;
//	}
//	printf("%lf", sum);
//	return 0;
//}

//int main()
//{
//	int arr[10], i, max;
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	max = arr[0];
//	for (i = 1; i < 10; i++)
//	{
//		if (max < arr[i])
//		{
//			max = arr[i];
//		}
//	}
//	printf("max = %d", max);
//	return 0;
//}

//int main()
//{
//	int i, j;
//	for (i = 1; i <= 9; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%-2d\t", j, i, i * j);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//int main()
//{
//	int i, sum = 0, ret = 1;
//	for (i = 1; i <= 10; i++)
//	{
//		ret *= i;
//		sum += ret;
//	}
//	printf("%d", sum);
//	return 0;
//}