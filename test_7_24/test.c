#include "seqlist.h"

void test1()
{
	SL s1;
	SLInit(&s1);
	SLPushBack(&s1, 1);
	SLPushBack(&s1, 2);
	SLPushBack(&s1, 3);
	SLPushBack(&s1, 4);
	SLPrint(&s1);

	SLPopBack(&s1);
	SLPrint(&s1);

	SLPushFront(&s1, 10);
	SLPushFront(&s1, 20);
	SLPushFront(&s1, 30);
	SLPushFront(&s1, 40);
	SLPrint(&s1);

	SLPopFront(&s1);
	SLPopFront(&s1);
	SLPopFront(&s1);
	SLPrint(&s1);

	SLInsert(&s1, 2, 11);
	SLInsert(&s1, 3, 12);
	SLInsert(&s1, 4, 13);
	SLPrint(&s1);

	SLErase(&s1, 4);
	SLErase(&s1, 2);
	SLErase(&s1, 4);
	SLPrint(&s1);

	SLDestroy(&s1);
}

int main()
{
	test1();
	return 0;
}