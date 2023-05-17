#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>

int main()
{
	int a, sn1;
	//Sn = a + aa + aaa + aaaa + aaaaa
	scanf("%d", &a);
	sn1 = a + a * a + a * a * a + a * a * a * a + a * a * a * a * a;
	printf("%d\n", sn1);

	int i, sn2 = 0;
	for (i = 1; i <= 5; i++)
	{
		sn2 += (int)pow(a, i);
	}
	printf("%d", sn2);
	return 0;
}

//#include <stdio.h>
//#include <math.h>
//
//int main()
//{
//	int i, count, num;
//	double sum;
//	for (i = 0; i <= 100000; i++)
//	{
//		int temp = i;
//		count = 0;
//		sum = 0;
//		while (temp)
//		{
//			count++;
//			temp /= 10;
//		}
//		temp = i;
//		while (temp)
//		{
//			num = temp % 10;
//			sum += pow(num, count);
//			temp /= 10;
//		}
//		if (sum == i)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}