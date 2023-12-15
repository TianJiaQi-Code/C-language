#include "snake.h"

// 设置光标的坐标
void SetPos(short x, short y)
{
	COORD pos = { x, y };
	HANDLE hOutput = NULL;
	// 获取标准输出的句柄（用来标识不同设备的数值）
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	// 设置标准输出上光标的位置为pos
	SetConsoleCursorPosition(hOutput, pos);
}

void WelComeToGame()
{
	SetPos(40, 14);		// 定位光标
	printf("欢迎来到贪吃蛇小游戏");
	SetPos(40, 25);
	system("pause");	// 暂停
	system("cls");		// 清屏
	SetPos(20, 14);
	printf("使用 ↑ . ↓ . ← . → 分别控制蛇的移动，F3是加速，F4是减速");
	SetPos(40, 25);
	system("pause");
	system("cls");
}

void CreateMap()
{
	int i = 0;
	// 上
	SetPos(0, 0);
	for (i = 0; i <= 56; i += 2)
	{
		wprintf(L"%lc", WALL);	// 打印宽字符
	}
	// 下
	SetPos(0, 26);
	for (i = 0; i <= 56; i += 2)
	{
		wprintf(L"%lc", WALL);
	}
	// 左
	for (i = 1; i <= 25; i++)
	{
		SetPos(0, i);
		wprintf(L"%lc", WALL);
	}
	// 右
	for (i = 1; i <= 25; i++)
	{
		SetPos(56, i);
		wprintf(L"%lc", WALL);
	}
}

void InitSnake(pSnake ps)
{
	pSnakeNode cur = NULL;
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		cur = (pSnakeNode)malloc(sizeof(SnakeNode));
		if (cur == NULL)
		{
			perror("InitSnake()::malloc()");
			return;
		}
		cur->x = POS_X + 2 * i;
		cur->y = POS_Y;
		cur->next = NULL;

		// 头插法
		if (ps->_pSnake == NULL)
		{
			ps->_pSnake = cur;
		}
		else
		{
			cur->next = ps->_pSnake;
			ps->_pSnake = cur;
		}
	}

	// 打印蛇身
	cur = ps->_pSnake;
	while (cur)
	{
		SetPos(cur->x, cur->y);
		wprintf(L"%lc", BODY);
		cur = cur->next;
	}

	ps->_Status = OK;
	ps->_Score = 0;
	ps->_pFood = NULL;
	ps->_SleepTime = 200;
	ps->_FoodWeight = 10;
	ps->_Dir = RIGHT;
}

void CreateFood(pSnake ps)
{
	int x = 0;
	int y = 0;
again:
	do
	{
		x = rand() % 53 + 2;
		y = rand() % 25 + 1;
	} while (x % 2 != 0);	// x坐标必须是2的倍数
	// 坐标不能和蛇的身体冲突
	pSnakeNode cur = ps->_pSnake;
	while (cur)
	{
		// 比较坐标
		if (cur->x == x && cur->y == y)
		{
			goto again;
		}
		cur = cur->next;
	}

	pSnakeNode pFood = (pSnakeNode)malloc(sizeof(SnakeNode));
	if (pFood == NULL)
	{
		perror("CreateFood()::malloc()");
		return;
	}
	pFood->x = x;
	pFood->y = y;
	ps->_pFood = pFood;

	// 打印食物
	SetPos(x, y);
	wprintf(L"%lc", FOOD);
}

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
	WelComeToGame();
	// 创建地图
	CreateMap();
	// 初始化贪吃蛇
	InitSnake(ps);
	// 创建食物
	CreateFood(ps);

	getchar();
}

