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

// (x-1,y-1) (x-1, y ) (x-1,y+1)   |   (1,1) (1,2) (1,3)
// ( x ,y-1) ( x , y ) ( x ,y+1)   |   (2,1) (2,2) (2.3)
// (x+1,y-1) (x+1, y ) (x+1,y+1)   |   (3,1) (3,2) (3,3)
int GetMineCount(char mine[ROWS][COLS], int x, int y)
{
	return (mine[x - 1][y] + mine[x - 1][y - 1] + mine[x][y - 1] +
		mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1] +
		mine[x][y + 1] + mine[x - 1][y + 1] - 8 * '0');
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
				//该位置不是雷，就统计这个坐标周围有几个雷
				int count = GetMineCount(mine, x, y);
				show[x][y] = count + '0';
				DisplayBoard(show, ROW, COL);
				win++;
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