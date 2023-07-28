#define _CRT_SECURE_NO_WARNINGS 1

#include "slist.h"

void test()
{
	SLTNode* plist = NULL;
	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPrint(plist);
}

int main()
{
	test();
	return 0;
}