#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
    double price;
    int month, day, coupon;
    scanf("%lf %d %d %d", &price, &month, &day, &coupon);
    if (month == 11)
    {
        if (day == 11)
        {
            price *= 0.7;
            if (coupon == 1)
            {
                price -= 50;
            }
        }
    }
    else if (month == 12)
    {
        if (day == 12)
        {
            price *= 0.8;
            if (coupon == 1)
            {
                price -= 50;
            }
        }
    }
    if (price < 0)
    {
        price = 0;
    }
    printf("%.2lf", price);
    return 0;
}

//#include <stdio.h>
//
//int main()
//{
//    char input;
//    while (scanf("%c", &input) != EOF)
//    {
//        getchar();
//        if ((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z'))
//        {
//            printf("%c is an alphabet.\n", input);
//        }
//        else
//        {
//            printf("%c is not an alphabet.\n", input);
//        }
//    }
//    return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//    int arr[4], i, max;
//    for (i = 0; i < 4; i++)
//    {
//        scanf("%d", &arr[i]);
//    }
//    max = arr[0];
//    for (i = 1; i < 4; i++)
//    {
//        if (max < arr[i])
//        {
//            max = arr[i];
//        }
//    }
//    printf("%d", max);
//    return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//    long long n = 0, sum = 0;
//    scanf("%lld", &n);
//    sum = (1 + n) * n / 2;
//    printf("%lld", sum);
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//void menu()
//{
//	printf("***************************\n");
//	printf("*******   1. play   *******\n");
//	printf("*******   0. exit   *******\n");
//	printf("***************************\n");
//}
//
//void game()
//{
//	int input, num;
//	num = rand() % 100 + 1;
//	do
//	{
//		printf("������һ��1~100������:");
//		scanf("%d", &input);
//		if (input > num)
//			printf("�´���\n");
//		else if (input < num)
//			printf("��С��\n");
//		else
//		{
//			printf("��ϲ�㣬�¶���!\n");
//			break;
//		}
//	}while (1);
//}
//
//int main()
//{
//	int input;
//	srand((unsigned int)time(NULL));
//	do
//	{
//		menu();
//		printf("��ѡ��:");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("�˳���Ϸ\n");
//			break;
//		default:
//			printf("ѡ�����������ѡ��!\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//    int m, n, i, count = 0;
//    scanf("%d%d", &m, &n);
//    for (i = 0; i < 32; i++)
//    {
//        if ((m & 1) != (n & 1))
//        {
//            count++;
//        }
//        m = m >> 1;
//        n = n >> 1;
//    }
//    printf("%d", count);
//    return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	int binary[33] = { 0 };
//	int input, i, flag = 1;
//	scanf("%d", &input);
//	for (i = 32; i >= 1; i--)
//	{
//		if ((input & flag) != 0)
//		{
//			binary[i]++;
//		}
//		flag = flag << 1;
//	}
//	printf("%d�Ķ�����������:", input);
//	for (i = 1; i <= 32; i++)
//	{
//		printf("%d", binary[i]);
//	}
//	printf("\n����λ:");
//	for (i = 1; i <= 31; i += 2)
//	{
//		printf("%d", binary[i]);
//	}
//	printf("\nż��λ:");
//	for (i = 2; i <= 32; i += 2)
//	{
//		printf("%d", binary[i]);
//	}
//	return 0;
//}