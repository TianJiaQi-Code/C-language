#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int arr[100][100] = { 0 };
	int input, i, j;
	scanf("%d", &input);
	for (i = 0; i < input; i++)
	{
		for (j = 0; j <= i; j++)
		{
			if (j == 0 || i == j)
			{
				arr[i][j] = 1;
			}
		}
	}
	for (i = 2; i < input; i++)
	{
		for (j = 1; j <= i - 1; j++)
		{
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
	}
	for (i = 0; i < input; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}

//�ձ�ĳ�ط�����һ��ıɱ��������ͨ���Ų�ȷ��ɱ�����ֱ�Ϊ4�����ɷ���һ����
//����Ϊ4�����ɷ��Ĺ���:
//A˵�������ҡ�
//B˵����C��
//C˵����D��
//D˵��C�ں�˵
//��֪3����˵���滰��1����˵���Ǽٻ���
//�����������Щ��Ϣ��дһ��������ȷ������˭�����֡�

//#include <stdio.h>
//
//int main()
//{
//	char murderer;
//	for (murderer = 'A'; murderer <= 'D'; murderer++)
//	{
//		if (((murderer != 'A') + (murderer == 'C') + (murderer == 'D') + (murderer != 'D')) == 3)
//		{
//			printf("%c������", murderer);
//			break;
//		}
//	}
//	return 0;
//}