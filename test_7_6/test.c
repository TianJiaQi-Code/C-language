#define _CRT_SECURE_NO_WARNINGS 1

//ʵ��һ�����������������ַ����е�k���ַ���
//���磺
//ABCD����һ���ַ��õ�BCDA
//ABCD���������ַ��õ�CDAB

#include <stdio.h>

void Levorotation(char str[], int k)
{
	int i;
	for (i = 0; i < k; i++)
	{
		char* p = str;//p = &str[0]
		char temp = str[0];
		while (*(p + 1) != '\0')
		{
			*p = *(p + 1);
			p++;
		}
		*p = temp;
	}
}

int main()
{
	char str[10] = "ABCD";
	int k;
	printf("������Ҫ�����ַ��ĸ�����");
	scanf("%d", &k);
	Levorotation(str, k);
	puts(str);
	return 0;
}

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
//			printf("�ҵ���\n");
//			flag = 1;
//		}
//	}
//	int j;
//	for (j = 0; j < 5; j++)
//	{
//		if (arr[4][j] == input)
//		{
//			printf("�ҵ���\n");
//			flag = 1;
//		}
//	}
//	if (flag == 0)
//	{
//		printf("û�ҵ�\n");
//	}
//	return 0;
//}