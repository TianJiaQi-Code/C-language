#include "snake.h"

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

	// ������ͼ

	// ��ʼ��̰����

	// ����ʳ��

	getchar();
}