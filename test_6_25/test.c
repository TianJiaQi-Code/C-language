#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int main()
{
	char str1[] = "\"hello\040world\"";
	printf("%d %d", strlen(str1), sizeof(str1));
	return 0;
}

//1.����ͬ���������ù�100ֻ����284ֻ�ţ��󼦺��õĸ�����
//#include <stdio.h>
//
//int main()
//{
//	int chicken = 100;
//	int rabbit = 0;
//	while (chicken >= 0 && rabbit >= 0)
//	{
//		if (chicken * 2 + rabbit * 4 == 284)
//		{
//			printf("����%dֻ,����%dֻ\n", chicken, rabbit);
//			break;
//		}
//		chicken--;
//		rabbit++;
//	}
//	return 0;
//}

//2.��e�Ľ���ֵ��e=1+1+1/2!+1/3!+...+1/n!��Ҫ��С��10�ĸ�4�η���
//#include <stdio.h>
//
//int main()
//{
//	double e = 1;
//	int factorial = 1;
//	int i = 2;
//	while (1.0 / factorial >= 1e-4)
//	{
//		e += 1.0 / factorial;
//		factorial = factorial * i;
//		i++;
//	}
//	printf("e = %lf\n", e);
//	return 0;
//}

//3.õ�廨��������1634���ڸ���λ����4�η�����1000��9999��õ�廨����
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

//4.����10����������������10�����������������ĺ͡�
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
//		int flag = 1;
//		int j;
//		for (j = 2; j < arr[i]; j++)
//		{
//			if (arr[i] % j == 0)
//			{
//				flag = 0;
//			}
//		}
//		if (flag)
//		{
//			printf("%hd ", arr[i]);
//			sum += arr[i];
//		}
//	}
//	printf("\nsum = %hd\n", sum);
//}