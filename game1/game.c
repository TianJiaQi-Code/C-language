#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

//��ʼ������Ϊ�ո�
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

//��ӡ����
void PrintBoard(char board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		//1.��ӡ����
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		//2.��ӡ�ָ���
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}

//���������������
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x, y;
	printf("�������\n");
	while (1)
	{
		printf("��������������꣬�м�ʹ�ÿո����:");
		scanf("%d %d", &x, &y);
		//����Ϸ�
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//��������
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = 'X';
				break;
			}
			//��������
			else
			{
				printf("���걻ռ��,��������,��������������\n");
			}
		}
		//����Ƿ�
		else
		{
			printf("����Ƿ�,����������\n");
		}
	}
}

//�����������
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x, y;
	printf("��������\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = 'O';
			break;
		}
	}
}

//�ж������Ƿ�ռ��
//δռ�� --- 0
//ռ  �� --- 1
int IsFull(char board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}

//�ж���Ӯ
char IsWin(char board[ROW][COL], int row, int col)
{
	//Ӯ
	int i;
	//��
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}
	}
	//��
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
		{
			return board[0][i];
		}
	}
	//�Խ���
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
		return board[0][0];
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
		return board[0][2];
	//ƽ��
	if (IsFull(board, row, col) == 1)
	{
		return 'Q';
	}
	//����
	return 'C';
}