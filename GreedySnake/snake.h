#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <windows.h>
#include <locale.h>

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