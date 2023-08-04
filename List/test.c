#include "list.h"

void test1()
{
	LTNode* plist = LTInit();
	LTPushBack(plist, 1);
	LTPushBack(plist, 2);
	LTPushBack(plist, 3);
	LTPrint(plist);

	LTPopBack(plist);
	LTPrint(plist);

	LTPushFront(plist, 10);
	LTPushFront(plist, 20);
	LTPushFront(plist, 30);
	LTPrint(plist);

	int size = LTSize(plist);
	printf("%d\n", size);

	LTPopFront(plist);
	LTPrint(plist);

	LTNode* pos = LTFind(plist, 1);
	if (pos)
	{
		LTInsert(pos, 100);
		LTPrint(plist);
	}
	
	pos = LTFind(plist, 10);
	if (pos)
	{
		LTErase(pos);
		LTPrint(plist);
	}

	LTDestroy(plist);
	plist = NULL;
}

int main()
{
	test1();
	return 0;
}