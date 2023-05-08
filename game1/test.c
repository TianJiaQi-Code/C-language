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
	InitBoard(board, ROW, COL);		//初始化棋盘
	PrintBoard(board, ROW, COL);	//打印棋盘
	//下棋
	char ret;
	while (1)
	{
		PlayerMove(board, ROW, COL);	//玩家下棋
		PrintBoard(board, ROW, COL);
		//判断输赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
		ComputerMove(board, ROW, COL);	//电脑下棋
		PrintBoard(board, ROW, COL);
		//判断输赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
	}
	if (ret == 'X')
		printf("玩家赢\n");
	else if (ret == 'O')
		printf("电脑赢\n");
	else
		printf("平局\n");
}

int main()
{
	int input;
	srand((unsigned int)time(NULL));
	do
	{
		menu();		//菜单
		printf("请选择:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误,请重新选择!\n");
			break;
		}
	} while (input);
	return 0;
}