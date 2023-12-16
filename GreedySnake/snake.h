#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <windows.h>
#include <locale.h>

#define WALL L'��'
#define BODY L'��'
#define FOOD L'��'

#define POS_X 24
#define POS_Y 5

#define KEY_PRESS(VK) ((GetAsyncKeyState(VK) & 0x1) ? 1 : 0)

enum DIRECTION
{
	UP = 1,
	DOWN,
	LEFT,
	RIGHT
};

enum GAME_STATUS
{
	OK,				// ��������
	END_NORMAL,		// ��ESC�˳�
	KILL_BY_WALL,	// ײǽ
	KILL_BY_SELF	// ��ɱ
};

// ̰���߽ڵ������
typedef struct SnakeNode
{
	// ����
	int x;
	int y;
	struct SnakeNode* next;
}SnakeNode, * pSnakeNode;

// ̰���ߵĽṹ
typedef struct Snake
{
	pSnakeNode _pSnake;			// ָ��̰����ͷ�ڵ��ָ��
	pSnakeNode _pFood;			// ָ��ʳ��ڵ��ָ��

	int _Score;					// ̰�����ۼƵ��ܷ�
	int _FoodWeight;			// һ��ʳ��ķ���
	int _SleepTime;				// ÿ��һ����Ϣ��ʱ�䣺ʱ��Խ�̣��ٶ�Խ�죻ʱ��Խ�����ٶ�Խ��

	enum DIRECTION _Dir;		// �����ߵķ���
	enum GAME_STATUS _Status;	// ��Ϸ��״̬���������˳���ײǽ���Ե��Լ�
}Snake, * pSnake;



// ��Ϸ��ʼ - �����Ϸ�ĳ�ʼ������
void GameStart(pSnake ps);
// ��λ����
void SetPos(short x, short y);
// ��Ϸ��ʼ�Ļ�ӭ����
void WelComeToGame();
// ��ӡ��ͼ
void CreateMap();
// ��ʼ��̰����
void InitSnake(pSnake ps);
// ����ʳ��
void CreateFood(pSnake ps);
// ��Ϸ��������
void GameRun(pSnake ps);
// ��ӡ������Ϣ
void PrintHelpInfo();
// ��Ϸ��ͣ�ͻָ�
void Pause();
// �ߵ��ƶ�
void SnakeMove(pSnake ps);
// �ж���ͷ��������괦�Ƿ���ʳ���ʳ�ﷵ��1�����򷵻�0
int NextIsFood(pSnake ps, pSnakeNode pnext);
// �Ե�ʳ��
void EatFood(pSnake ps, pSnakeNode pnext);
// ����ʳ��
void NoFood(pSnake ps, pSnakeNode pnext);
// ���Ƿ�ײǽ
void KillByWall(pSnake ps);
// ���Ƿ���ɱ
void KillBySelf(pSnake ps);
// ��Ϸ��������ƺ���
void GameEnd(pSnake ps);