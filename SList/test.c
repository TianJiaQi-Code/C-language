#define _CRT_SECURE_NO_WARNINGS 1

#include "slist.h"

void test1()
{
	SLTNode* plist = NULL;
	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPrint(plist);

	SLTPushFront(&plist, 10);
	SLTPushFront(&plist, 20);
	SLTPushFront(&plist, 30);
	SLTPrint(plist);

	SLTPopBack(&plist);
	SLTPrint(plist);

	SLTPopFront(&plist);
	SLTPrint(plist);
}

void test2()
{
	SLTNode* plist = NULL;
	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	SLTPushBack(&plist, 5);
	SLTPrint(plist);

	SLTNode* pos = SLTFind(plist, 5);
	if (pos)
	{
		pos->data *= 10;
	}
	SLTPrint(plist);

	int x;
	scanf("%d", &x);
	pos = SLTFind(plist, x);
	if (pos)
	{
		SLTInsert(&plist, pos, x * 10);
	}
	SLTPrint(plist);
}

void test3()
{
	SLTNode* plist = NULL;
	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	SLTPushBack(&plist, 5);
	SLTPrint(plist);

	SLTNode* pos = SLTFind(plist, 2);
	if (pos)
	{
		SLTInsertAfter(pos, 100);
		SLTInsertAfter(pos, 200);
	}
	SLTPrint(plist);

	pos = SLTFind(plist, 200);
	if (pos)
	{
		SLTErase(&plist, pos);
	}
	SLTPrint(plist);

	pos = SLTFind(plist, 100);
	if (pos)
	{
		SLTEraseAfter(pos);
	}
	SLTPrint(plist);

	SLTDestroy(&plist);
}

int main()
{
	test3();
	return 0;
}