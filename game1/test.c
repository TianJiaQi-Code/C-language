#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void menu()
{
	printf("***************************\n");
	printf("*******   1. paly   *******\n");
	printf("*******   0. exit   *******\n");
	printf("***************************\n");
}

void game()
{
	char board[ROW][COL];
	InitBoard(board, ROW, COL);		//��ʼ������
	PrintBoard(board, ROW, COL);	//��ӡ����
	//����
	char ret;
	while (1)
	{
		PlayerMove(board, ROW, COL);	//�������
		PrintBoard(board, ROW, COL);
		//�ж���Ӯ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
		ComputerMove(board, ROW, COL);	//��������
		PrintBoard(board, ROW, COL);
		//�ж���Ӯ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
	}
	if (ret == 'X')
		printf("���Ӯ\n");
	else if (ret == 'O')
		printf("����Ӯ\n");
	else
		printf("ƽ��\n");
}

int main()
{
	int input;
	srand((unsigned int)time(NULL));
	do
	{
		menu();		//�˵�
		printf("��ѡ��:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����,������ѡ��!\n");
			break;
		}
	} while (input);
	return 0;
}