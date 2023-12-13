#define _CRT_SECURE_NO_WARNINGS 1

#include "snake.h"

void test()
{
	Snake snake = { 0 };// 创建了贪吃蛇
	// 1. 游戏开始 - 初始化游戏
	GameStart(&snake);
	// 2. 游戏运行 - 游戏的正常运行过程

	// 3. 游戏结束 - 游戏善后（释放资源）

}

int main()
{
	// 设置程序适应本地环境
	setlocale(LC_ALL, "");

	test();

	return 0;
}