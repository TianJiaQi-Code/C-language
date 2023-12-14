#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <windows.h>
#include <locale.h>

#define WALL L'□'
#define BODY L'●'
#define FOOD L'★'

#define POS_X 24
#define POS_Y 5

enum DIRECTION
{
	UP = 1,
	DOWN,
	LEFT,
	RIGHT
};

enum GAME_STATUS
{
	OK,				// 正常运行
	END_NORMAL,		// 按ESC退出
	KILL_BY_WALL,	// 撞墙
	KILL_BY_SELF	// 自杀
};

// 贪吃蛇节点的描述
typedef struct SnakeNode
{
	// 坐标
	int x;
	int y;
	struct SnakeNode* next;
}SnakeNode, * pSnakeNode;

// 贪吃蛇的结构
typedef struct Snake
{
	pSnakeNode _pSnake;			// 指向贪吃蛇头节点的指针
	pSnakeNode _pFood;			// 指向食物节点的指针

	int _Score;					// 贪吃蛇累计的总分
	int _FoodWeight;			// 一个食物的分数
	int _SleepTime;				// 每走一步休息的时间：时间越短，速度越快；时间越长，速度越慢

	enum DIRECTION _Dir;		// 描述蛇的方向
	enum GAME_STATUS _Status;	// 游戏的状态：正常、退出、撞墙、吃到自己
}Snake, * pSnake;



// 游戏开始 - 完成游戏的初始化动作
void GameStart(pSnake ps);
// 定位坐标
void SetPos(short x, short y);
// 游戏开始的欢迎界面
void WelComeToGame();
// 打印地图
void CreateMap();
// 初始化贪吃蛇
void InitSnake(pSnake ps);
// 创建食物
void CreateFood(pSnake ps);