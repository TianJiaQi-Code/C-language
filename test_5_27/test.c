#define _CRT_SECURE_NO_WARNINGS 1

//5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果：
//A选手说：B第二，我第三；
//B选手说：我第二，E第四；
//C选手说：我第一，D第二；
//D选手说：C最后，我第三；
//E选手说：我第四，A第一；
//比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。

#include <stdio.h>

int CheckData(int* p)
{
	int tmp[7] = {0};
	int i;
	for (i = 0; i < 5; i++)
	{
		if (tmp[p[i]])
		{
			return 0;
		}
		tmp[p[i]] = 1;
	}
	return 1;
}

int main()
{
	int p[5];
	for (p[0] = 1; p[0] <= 5; p[0]++)
	{
		for (p[1] = 1; p[1] <= 5; p[1]++)
		{
			for (p[2] = 1; p[2] <= 5; p[2]++)
			{
				for (p[3] = 1; p[3] <= 5; p[3]++)
				{
					for (p[4] = 1; p[4] <= 5; p[4]++)
					{
						if ((p[1] == 2) + (p[0] == 3) == 1 &&
							(p[1] == 2) + (p[4] == 4) == 1 &&
							(p[2] == 1) + (p[3] == 2) == 1 &&
							(p[2] == 5) + (p[3] == 3) == 1 &&
							(p[4] == 4) + (p[0] == 1) == 1 &&
							CheckData(p))
						{
							for (int i = 0; i < 5; i++)
							{
								printf("%d ", p[i]);
							}
							putchar('\n');
						}
					}
				}
			}
		}
	}
	return 0;
}

//0x1234
//大端 - 1234

//unsigned int a = 0x1234;
//unsigned char b = *(unsigned char*)&a;

//char -> -128 ~ 127
//unsigned char -> 0 ~ 255
//00000000 00000000 00000000 11001000 - 200
//00000000 00000000 00000000 01100100 - 100
//00000000 00000000 00000001 00101100 - 44

//int main()
//{
//	unsigned char a = 200;
//	unsigned char b = 100;
//	unsigned char c = 0;
//	c = a + b;
//	printf(“ % d % d”, a + b, c);
//	return 0;
//}