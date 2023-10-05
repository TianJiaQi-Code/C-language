#define _CRT_SECURE_NO_WARNINGS 1
//#include "heap.h"
#include "BinaryTree.h"

int main()
{
	// 手动构建
	BTNode* node1 = BuyNode(1);
	BTNode* node2 = BuyNode(2);
	BTNode* node3 = BuyNode(3);
	BTNode* node4 = BuyNode(4);
	BTNode* node5 = BuyNode(5);
	BTNode* node6 = BuyNode(6);
	BTNode* node7 = BuyNode(7);
	BTNode* node8 = BuyNode(8);
	BTNode* node9 = BuyNode(9);

	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node4->left = node5;
	node4->right = node6;
	node2->right = node7;
	node3->left = node8;
	node6->right = node9;

	PrevOrder(node1);
	printf("\n");

	InOrder(node1);
	printf("\n");

	PostOrder(node1);
	printf("\n");

	printf("TreeSize:%d\n", TreeSize(node1));
	//printf("TreeComplete:%d\n", TreeComplete(node1));
	printf("TreeHeight:%d\n", TreeHeight(node1));

	TreeDestroy(node1);
	node1 = NULL;

	return 0;
}

//// 堆排序
//void HeapSort(int* a, int n)
//{
//	// 向下调整建堆
//	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
//	{
//		AdjustDown(a, n, i);
//	}
//	int end = n - 1;
//	while (end > 0)
//	{
//		Swap(&a[0], &a[end]);
//		AdjustDown(a, end, 0);
//		--end;
//	}
//}
//
//void CreateNDate()
//{
//	// 造数据
//	int n = 10000000;
//	srand((unsigned int)time(0));
//	const char* file = "data.txt";
//	FILE* fin = fopen(file, "w");
//	if (fin == NULL)
//	{
//		perror("fopen error");
//		return;
//	}
//	for (int i = 0; i < n; ++i)
//	{
//		int x = (rand() + i) % 10000000;
//		fprintf(fin, "%d\n", x);
//	}
//	fclose(fin);
//}
//
//// 文件的TopK问题
//void PrintTopK(const char* filename, int k)
//{
//	// 建堆，用a中前k个元素建堆
//	FILE* fout = fopen(filename, "r");
//	if (fout == NULL)
//	{
//		perror("fopen fail");
//		return;
//	}
//	int* minheap = (int*)malloc(sizeof(int) * k);
//	if (minheap == NULL)
//	{
//		perror("malloc fail");
//		return;
//	}
//	for (int i = 0; i < k; i++)
//	{
//		fscanf(fout, "%d", &minheap[i]);
//	}
//	// 前k个数建小堆
//	for (int i = (k - 2) / 2; i >= 0; --i)
//	{
//		AdjustDown(minheap, k, i);
//	}
//	// 将剩余n-k个元素依次与堆顶元素比较
//	int x = 0;
//	while (fscanf(fout, "%d", &x) != EOF)
//	{
//		if (x > minheap[0])
//		{
//			// 替换你进堆
//			minheap[0] = x;
//			AdjustDown(minheap, k, 0);
//		}
//	}
//
//	for (int i = 0; i < k; i++)
//	{
//		printf("%d ", minheap[i]);
//	}
//	printf("\n");
//
//	free(minheap);
//	fclose(fout);
//}
//
//int main()
//{
//	//CreateNDate();
//	PrintTopK("data.txt", 5);
//	return 0;
//}

//int main()
//{
//	int a[] = { 30,98,79,54,1,-5,-99,299,999 };
//	int sz = sizeof(a) / sizeof(a[0]);
//	HeapSort(a, sz);
//	for (int i = 0; i < sz; i++)
//		printf("%d ", a[i]);
//	return 0;
//}

//int main()
//{
//	int a[] = { 2,5,7,9,3,1,0,50,80,70,60,11,111 };
//	HP hp;
//	HeapInit(&hp);
//	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
//	{
//		HeapPush(&hp, a[i]);
//	}
//	HeapPrint(&hp);
//
//	int k = 10;
//	while (!HeapEmpty(&hp) && k--)
//	{
//		printf("%d ", HeapTop(&hp));
//		HeapPop(&hp);
//	}
//
//	HeapDestroy(&hp);
//	return 0;
//}