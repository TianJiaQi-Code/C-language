#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

//初始化棋盘为空格
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

//打印棋盘
void PrintBoard(char board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		//1.打印数据
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		//2.打印分割线
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

//玩家输入坐标下棋
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x, y;
	printf("玩家下棋\n");
	while (1)
	{
		printf("请输入下棋的坐标，中间使用空格隔开:");
		scanf("%d %d", &x, &y);
		//坐标合法
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//可以落子
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = 'X';
				break;
			}
			//不能落子
			else
			{
				printf("坐标被占有,不能落子,请重新输入坐标\n");
			}
		}
		//坐标非法
		else
		{
			printf("坐标非法,请重新输入\n");
		}
	}
}

//电脑随机下棋
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x, y;
	printf("电脑下棋\n");
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

//判断棋盘是否被占满
//未占满 --- 0
//占  满 --- 1
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

//判断输赢
char IsWin(char board[ROW][COL], int row, int col)
{
	//赢
	int i;
	//行
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}
	}
	//列
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
		{
			return board[0][i];
		}
	}
	//对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
		return board[0][0];
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
		return board[0][2];
	//平局
	if (IsFull(board, row, col) == 1)
	{
		return 'Q';
	}
	//继续
	return 'C';
}