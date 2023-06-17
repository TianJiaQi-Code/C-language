#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define EASY_COUNT 10	//雷的个数

#define ROW 9	//雷区的行数
#define COL 9	//雷区的列数

//二维数组的大小，比雷区大一圈方便计算
#define ROWS ROW+2
#define COLS COL+2

//初始化棋盘
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);

//打印棋盘
void DisplayBoard(char board[ROWS][COLS], int row, int col);

//布置雷
void SetMine(char board[ROWS][COLS], int row, int col);

//排查雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);