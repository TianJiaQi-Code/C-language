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

//判断输赢 --- 五子棋的判断
char IsWin(char board[ROW][COL], int row, int col)
{
	int i, j;
	//判断每行有五个相同的棋子
	//假设有6列，COL=col=6，每行五子相同有以下两种可能性
	// 0 1 2 3 4 5 （列的下标）
	// X X X X X		（把“X”当作棋子）
	//   X X X X X
	//我们要拿五个棋子中的【第一个棋子】去跟【后面的四个棋子】比较一下是否相同
	//可以看到j的范围在0~1之间，也就是:for (j = 0; j < col - 4; j++)
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col - 4; j++)
		{
			if (board[i][j] == board[i][j + 1] &&
				board[i][j + 1] == board[i][j + 2] &&
				board[i][j + 2] == board[i][j + 3] &&
				board[i][j + 3] == board[i][j + 4] &&
				board[i][j] != ' ')
			{
				return board[i][j];
			}
		}
	}
	//判断每列有五个相同的棋子
	//原理同上，i的范围：for (i = 0; i < row - 4; i++)
	for (j = 0; j < col; j++)
	{
		for (i = 0; i < row - 4; i++)
		{
			if (board[i][j] == board[i + 1][j] &&
				board[i + 1][j] == board[i + 2][j] &&
				board[i + 2][j] == board[i + 3][j] &&
				board[i + 3][j] == board[i + 4][j] &&
				board[i][j] != ' ')
			{
				return board[i][j];
			}
		}
	}
	//判断\方向有五个相同的棋子
	//假设有6行6列，有以下四种可能性
	//   0 1 2 3 4 5  |    0 1 2 3 4 5
	// 0 X X          |  0
	// 1   X X        |  1 X X
	// 2     X X      |  2   X X
	// 3       X X    |  3     X X
	// 4         X X  |  4       X X
	// 5              |  5         X X
	//由于我们要拿五个棋子中的【第一个棋子】去跟【后面的四个棋子】比较
	//所以(i,j)的可能取值:(0,0) (0,1) (1,0) (1,1)
	for (i = 0; i < row - 4; i++)
	{
		for (j = 0; j < col - 4; j++)
		{
			if (board[i][j] == board[i + 1][j + 1] &&
				board[i + 1][j + 1] == board[i + 2][j + 2] &&
				board[i + 2][j + 2] == board[i + 3][j + 3] &&
				board[i + 3][j + 3] == board[i + 4][j + 4] &&
				board[i][j] != ' ')
			{
				return board[i][j];
			}
		}
	}
	//判断/方向有五个相同的棋子
	//假设有6行6列，同样有以下四种可能性
	//   0 1 2 3 4 5  |    0 1 2 3 4 5
	// 0         X X  |  0
	// 1       X X    |  1         X X
	// 2     X X      |  2       X X
	// 3   X X        |  3     X X
	// 4 X X          |  4   X X
	// 5              |  5 X X
	//(i,j)的可能取值:(0,4) (0,5) (1,4) (1,5)
	for (i = 0; i < row - 4; i++)
	{
		for (j = 4; j < col; j++)
		{
			if (board[i][j] == board[i + 1][j - 1] &&
				board[i + 1][j - 1] == board[i + 2][j - 2] &&
				board[i + 2][j - 2] == board[i + 3][j - 3] &&
				board[i + 3][j - 3] == board[i + 4][j - 4] &&
				board[i][j] != ' ')
			{
				return board[i][j];
			}
		}
	}
	//平局(棋盘被占满还未分出胜负)
	if (IsFull(board, row, col) == 1)
	{
		return 'Q';
	}
	//继续
	return 'C';
}

//判断输赢 --- 三子棋的判断
//char IsWin(char board[ROW][COL], int row, int col)
//{
//	//赢
//	int i;
//	//行
//	for (i = 0; i < row; i++)
//	{
//		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
//		{
//			return board[i][0];
//		}
//	}
//	//列
//	for (i = 0; i < col; i++)
//	{
//		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
//		{
//			return board[0][i];
//		}
//	}
//	//对角线
//	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
//		return board[0][0];
//	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
//		return board[0][2];
//	//平局
//	if (IsFull(board, row, col) == 1)
//	{
//		return 'Q';
//	}
//	//继续
//	return 'C';
//}