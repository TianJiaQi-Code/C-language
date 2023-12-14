#include "snake.h"

void GameStart(pSnake ps)
{
	// 控制台窗口设置
	system("mode con cols=100 lines=30");
	system("title 贪吃蛇");
	// 光标隐藏
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	// 隐藏光标操作
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(hOutput, &CursorInfo);	// 获取控制台光标信息
	CursorInfo.bVisible = false;				// 隐藏控制台光标
	SetConsoleCursorInfo(hOutput, &CursorInfo);	// 设置控制台光标状态
	// 打印欢迎界面

	// 创建地图

	// 初始化贪吃蛇

	// 创建食物

	getchar();
}