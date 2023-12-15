#include "snake.h"

// ���ù�������
void SetPos(short x, short y)
{
	COORD pos = { x, y };
	HANDLE hOutput = NULL;
	// ��ȡ��׼����ľ����������ʶ��ͬ�豸����ֵ��
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	// ���ñ�׼����Ϲ���λ��Ϊpos
	SetConsoleCursorPosition(hOutput, pos);
}

void WelComeToGame()
{
	SetPos(40, 14);		// ��λ���
	printf("��ӭ����̰����С��Ϸ");
	SetPos(40, 25);
	system("pause");	// ��ͣ
	system("cls");		// ����
	SetPos(20, 14);
	printf("ʹ�� �� . �� . �� . �� �ֱ�����ߵ��ƶ���F3�Ǽ��٣�F4�Ǽ���");
	SetPos(40, 25);
	system("pause");
	system("cls");
}

void CreateMap()
{
	int i = 0;
	// ��
	SetPos(0, 0);
	for (i = 0; i <= 56; i += 2)
	{
		wprintf(L"%lc", WALL);	// ��ӡ���ַ�
	}
	// ��
	SetPos(0, 26);
	for (i = 0; i <= 56; i += 2)
	{
		wprintf(L"%lc", WALL);
	}
	// ��
	for (i = 1; i <= 25; i++)
	{
		SetPos(0, i);
		wprintf(L"%lc", WALL);
	}
	// ��
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

		// ͷ�巨
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

	// ��ӡ����
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
	} while (x % 2 != 0);	// x���������2�ı���
	// ���겻�ܺ��ߵ������ͻ
	pSnakeNode cur = ps->_pSnake;
	while (cur)
	{
		// �Ƚ�����
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

	// ��ӡʳ��
	SetPos(x, y);
	wprintf(L"%lc", FOOD);
}

void GameStart(pSnake ps)
{
	// ����̨��������
	system("mode con cols=100 lines=30");
	system("title ̰����");

	// �������
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	// ���ع�����
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(hOutput, &CursorInfo);	// ��ȡ����̨�����Ϣ
	CursorInfo.bVisible = false;				// ���ؿ���̨���
	SetConsoleCursorInfo(hOutput, &CursorInfo);	// ���ÿ���̨���״̬
	
	// ��ӡ��ӭ����
	WelComeToGame();
	// ������ͼ
	CreateMap();
	// ��ʼ��̰����
	InitSnake(ps);
	// ����ʳ��
	CreateFood(ps);

	getchar();
}

