#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 10	//���̵�����
#define COL 10	//���̵�����

//��ʼ������
void InitBoard(char board[ROW][COL], int row, int col);
//��ӡ����
void PrintBoard(char board[ROW][COL], int row, int col);
//�������
void PlayerMove(char board[ROW][COL], int row, int col);
//��������
void ComputerMove(char board[ROW][COL], int row, int col);
//�ж���Ӯ
//���Ӯ --- 'X'
//����Ӯ --- 'O'
//ƽ  �� --- 'Q'
//��  �� --- 'C'
char IsWin(char board[ROW][COL], int row, int col);