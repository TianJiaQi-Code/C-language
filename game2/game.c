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
	printf("------扫雷游戏------\n");
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
	//布置10个雷
	//生成随机的坐标，布置雷
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

//统计(x,y)坐标周围雷的个数
// (x-1,y-1) (x-1, y ) (x-1,y+1)
// ( x ,y-1) ( x , y ) ( x ,y+1)
// (x+1,y-1) (x+1, y ) (x+1,y+1)
int GetMineCount(char mine[ROWS][COLS], int x, int y)
{
	return (mine[x - 1][y] + mine[x - 1][y - 1] + mine[x][y - 1] +
		mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1] +
		mine[x][y + 1] + mine[x - 1][y + 1] - 8 * '0');
}

//递归展开
void Expand(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y, int* p_win)
{
	//(x,y)周围没有雷
	if (GetMineCount(mine, x, y) == 0)
	{
		//把(x,y)置为空格
		show[x][y] = ' ';
		int i, j;
		//循环找到(x,y)周围的八个坐标
		for (i = x - 1; i <= x + 1; i++)
		{
			for (j = y - 1; j <= y + 1; j++)
			{
				//设置条件避免死递归：坐标必须未被排查过，并且不能越界
				if (show[i][j] == '*' && i > 0 && i <= row && j > 0 && j <= col)
				{
					//找到一个新的坐标重复此过程
					Expand(mine, show, ROW, COL, i, j, p_win);
				}
			}
		}
	}
	//(x,y)周围有雷
	else
	{
		//在棋盘上显示出(x,y)周围有几个雷
		show[x][y] = GetMineCount(mine, x, y) + '0';
	}
	//统计已被排查区域个数
	(*p_win)++;
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x, y;
	int win = 0;
	while (win < row * col - EASY_COUNT)
	{
		printf("请输入要排查的坐标:");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("很遗憾，你被炸死了\n");
				DisplayBoard(mine, ROW, COL);
				break;
			}
			else if(mine[x][y] == '0' && show[x][y] == '*')
			{
				//如果该位置没有雷，就展开周围八格，如果被展开的位置还是没有雷，就继续展开
				Expand(mine, show, ROW, COL, x, y, &win);
				DisplayBoard(show, ROW, COL);
				printf("您已排查%d块区域，还有%d块区域待排查\n", win, row * col - EASY_COUNT - win);
			}
			else
			{
				printf("该坐标已被排查，请重新输入\n");
			}
		}
		else
		{
			printf("坐标非法，请重新输入\n");
		}
	}
	if (win == row * col - EASY_COUNT)
	{
		printf("你赢了！\n");
		DisplayBoard(mine, ROW, COL);
	}
}