#define _CRT_SECURE_NO_WARNINGS 1
#include "heap.h"

// ������
void HeapSort(int* a, int n)
{
	// ���µ�������
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}

void CreateNDate()
{
	// ������
	int n = 10000000;
	srand((unsigned int)time(0));
	const char* file = "data.txt";
	FILE* fin = fopen(file, "w");
	if (fin == NULL)
	{
		perror("fopen error");
		return;
	}
	for (int i = 0; i < n; ++i)
	{
		int x = (rand() + i) % 10000000;
		fprintf(fin, "%d\n", x);
	}
	fclose(fin);
}

// �ļ���TopK����
void PrintTopK(const char* filename, int k)
{
	// ���ѣ���a��ǰk��Ԫ�ؽ���
	FILE* fout = fopen(filename, "r");
	if (fout == NULL)
	{
		perror("fopen fail");
		return;
	}
	int* minheap = (int*)malloc(sizeof(int) * k);
	if (minheap == NULL)
	{
		perror("malloc fail");
		return;
	}
	for (int i = 0; i < k; i++)
	{
		fscanf(fout, "%d", &minheap[i]);
	}
	// ǰk������С��
	for (int i = (k - 2) / 2; i >= 0; --i)
	{
		AdjustDown(minheap, k, i);
	}
	// ��ʣ��n-k��Ԫ��������Ѷ�Ԫ�رȽ�
	int x = 0;
	while (fscanf(fout, "%d", &x) != EOF)
	{
		if (x > minheap[0])
		{
			// �滻�����
			minheap[0] = x;
			AdjustDown(minheap, k, 0);
		}
	}

	for (int i = 0; i < k; i++)
	{
		printf("%d ", minheap[i]);
	}
	printf("\n");

	free(minheap);
	fclose(fout);
}

int main()
{
	//CreateNDate();
	PrintTopK("data.txt", 5);
	return 0;
}

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