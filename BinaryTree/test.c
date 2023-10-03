#include "heap.h"

int main()
{
	int a[] = { 2,5,7,9,3,1,0,50,80,70,60,11,111 };
	HP hp;
	HeapInit(&hp);
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		HeapPush(&hp, a[i]);
	}
	HeapPrint(&hp);

	int k = 10;
	while (!HeapEmpty(&hp) && k--)
	{
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);
	}

	HeapDestroy(&hp);
	return 0;
}