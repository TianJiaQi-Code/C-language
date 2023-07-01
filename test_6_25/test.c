#define _CRT_SECURE_NO_WARNINGS

//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
//	char str1[] = "\"hello\040world\"";
//	printf("%d %d", strlen(str1), sizeof(str1));
//	return 0;
//}

//1.鸡兔同笼，鸡和兔共100只，共284只脚，求鸡和兔的个数。
//#include <stdio.h>
//
//int main()
//{
//	//假设有100只鸡，0只兔
//	int chicken = 100;
//	int rabbit = 0;
//	while (chicken >= 0 && rabbit >= 0)//鸡兔的个数不可能为负
//	{
//		if (chicken * 2 + rabbit * 4 == 284)
//		{
//			printf("鸡有%d只,兔有%d只\n", chicken, rabbit);
//			break;
//		}
//		//鸡-1，兔+1，总数还是100
//		chicken--;
//		rabbit++;
//	}
//	return 0;
//}

//2.求e的近似值，e=1+1+1/2!+1/3!+...+1/n!，要求小于10的负4次方。
//#include <stdio.h>
//
//int main()
//{
//	double e = 1;
//	int n = 1;
//	int i = 2;
//	while (1.0 / n >= 1e-4)//1e-4就是10的负4次方
//	{
//		e += 1.0 / n;
//		n = n * i;
//		i++;
//	}
//	printf("e = %lf\n", e);
//	return 0;
//}

//3.玫瑰花数，比如1634等于各个位数的4次方，求1000到9999的玫瑰花数。
//#include <stdio.h>
//#include <math.h>
//
//int main()
//{
//	int sum;
//	int i;
//	for (i = 1000; i <= 9999; i++)
//	{
//		sum = 0;
//		int temp = i;
//		while (temp != 0)
//		{
//			sum += (int)pow(temp % 10, 4);
//			temp /= 10;
//		}
//		if (i == sum)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}

//4.输入10个短整型数，计算10个短整型数中素数的和。
#include <stdio.h>

int main()
{
	short arr[10] = { 0 };
	short sum = 0;
	int i;
	//1.输入10个短整型数
	for (i = 0; i < 10; i++)
	{
		scanf("%hd", &arr[i]);
	}
	//2.遍历数组，判断是否为素数
	for (i = 0; i < 10; i++)
	{
		int flag = 1;//此变量用于判断，flag=1代表是素数，flag=0则不是素数
		//注意：只有大于1的数字才有可能是素数
		if (arr[i] > 1)
		{
			int j;
			for (j = 2; j < arr[i]; j++)
			{
				//如果被整除，说明该数字不是素数，把flag改为0
				if (arr[i] % j == 0)
				{
					flag = 0;
				}
			}
		}
		//若该数字小于等于1，则该数字不可能为素数
		else
		{
			flag = 0;
		}
		//3.如果是素数，就把他们的和加起来
		if (flag)
		{
			sum += arr[i];
		}
	}
	//4.打印结果
	printf("sum = %hd\n", sum);
}

//#include <stdio.h>
//
//int main()
//{
//	short arr[10] = { 0 };
//	short sum = 0;
//	int i;
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%hd", &arr[i]);
//	}
//	for (i = 0; i < 10; i++)
//	{
//		int j;
//		for (j = 2; j < arr[i]; j++)
//		{
//			if (arr[i] % j == 0)
//			{
//				break;
//			}
//		}
//		if (j >= arr[i])
//		{
//			printf("%d %hd ", j, arr[i]);
//			printf("sum = %hd\n", sum);
//			sum += arr[i];
//		}
//	}
//	printf("sum = %hd\n", sum);
//	return 0;
//}