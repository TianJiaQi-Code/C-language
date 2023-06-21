#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i;
	for (i = 0; i < rows; i++)
	{
		int j;
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i;
	printf("------ɨ����Ϸ------\n");
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		int j;
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("--------------------\n");
}

void SetMine(char board[ROWS][COLS], int row, int col)
{
	//����10����
	//������������꣬������
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

//ͳ��(x,y)������Χ�׵ĸ���
// (x-1,y-1) (x-1, y ) (x-1,y+1)
// ( x ,y-1) ( x , y ) ( x ,y+1)
// (x+1,y-1) (x+1, y ) (x+1,y+1)
int GetMineCount(char mine[ROWS][COLS], int x, int y)
{
	return (mine[x - 1][y] + mine[x - 1][y - 1] + mine[x][y - 1] +
		mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1] +
		mine[x][y + 1] + mine[x - 1][y + 1] - 8 * '0');
}

//�ݹ�չ��
void Expand(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y, int* p_win)
{
	//(x,y)��Χû����
	if (GetMineCount(mine, x, y) == 0)
	{
		//��(x,y)��Ϊ�ո�
		show[x][y] = ' ';
		int i, j;
		//ѭ���ҵ�(x,y)��Χ�İ˸�����
		for (i = x - 1; i <= x + 1; i++)
		{
			for (j = y - 1; j <= y + 1; j++)
			{
				//���������������ݹ飺�������δ���Ų�������Ҳ���Խ��
				if (show[i][j] == '*' && i > 0 && i <= row && j > 0 && j <= col)
				{
					//�ҵ�һ���µ������ظ��˹���
					Expand(mine, show, ROW, COL, i, j, p_win);
				}
			}
		}
	}
	//(x,y)��Χ����
	else
	{
		//����������ʾ��(x,y)��Χ�м�����
		show[x][y] = GetMineCount(mine, x, y) + '0';
	}
	//ͳ���ѱ��Ų��������
	(*p_win)++;
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x, y;
	int win = 0;
	while (win < row * col - EASY_COUNT)
	{
		printf("������Ҫ�Ų������:");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("���ź����㱻ը����\n");
				DisplayBoard(mine, ROW, COL);
				break;
			}
			else if(mine[x][y] == '0' && show[x][y] == '*')
			{
				//�����λ��û���ף���չ����Χ�˸������չ����λ�û���û���ף��ͼ���չ��
				Expand(mine, show, ROW, COL, x, y, &win);
				DisplayBoard(show, ROW, COL);
				printf("�����Ų�%d�����򣬻���%d��������Ų�\n", win, row * col - EASY_COUNT - win);
			}
			else
			{
				printf("�������ѱ��Ų飬����������\n");
			}
		}
		else
		{
			printf("����Ƿ�������������\n");
		}
	}
	if (win == row * col - EASY_COUNT)
	{
		printf("��Ӯ�ˣ�\n");
		DisplayBoard(mine, ROW, COL);
	}
}