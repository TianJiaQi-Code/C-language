#include <time.h>
#include <stdlib.h>
#include "Sort.h"

void TestInsertSort()
{
	int arr[10] = { 9,1,3,5,2,7,8,0,6,4 };
	InsertSort(arr, sizeof(arr) / sizeof(arr[0]));
	PrintArray(arr, sizeof(arr) / sizeof(arr[0]));
}

void TestShellSort()
{
	int arr[10] = { 9,1,3,5,2,7,8,0,6,4 };
	ShellSort(arr, sizeof(arr) / sizeof(arr[0]));
	PrintArray(arr, sizeof(arr) / sizeof(arr[0]));
}

void TestBubbleSort()
{
	int arr[10] = { 9,1,3,5,2,7,8,0,6,4 };
	BubbleSort(arr, sizeof(arr) / sizeof(arr[0]));
	PrintArray(arr, sizeof(arr) / sizeof(arr[0]));
}

void TestHeapSort()
{
	int arr[10] = { 9,1,3,5,2,7,8,0,6,4 };
	HeapSort(arr, sizeof(arr) / sizeof(arr[0]));
	PrintArray(arr, sizeof(arr) / sizeof(arr[0]));
}

void TestSelectSort()
{
	int arr[10] = { 9,1,3,5,2,7,8,0,6,4 };
	SelectSort(arr, sizeof(arr) / sizeof(arr[0]));
	PrintArray(arr, sizeof(arr) / sizeof(arr[0]));
}

void TestQuickSort()
{
	int arr[10] = { 9,1,3,5,2,7,8,0,6,4 };
	QuickSort(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
	PrintArray(arr, sizeof(arr) / sizeof(arr[0]));
}

void TestQuickSort1()
{
	int arr[10] = { 9,1,3,5,2,7,8,0,6,4 };
	QuickSort1(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
	PrintArray(arr, sizeof(arr) / sizeof(arr[0]));
}

void TestQuickSortNonR()
{
	int arr[10] = { 9,1,3,5,2,7,8,0,6,4 };
	QuickSortNonR(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
	PrintArray(arr, sizeof(arr) / sizeof(arr[0]));
}

void TestMergeSort()
{
	int arr[10] = { 9,1,3,5,2,7,8,0,6,4 };
	SelectSort(arr, sizeof(arr) / sizeof(arr[0]));
	PrintArray(arr, sizeof(arr) / sizeof(arr[0]));
}

void TestMergeSortNonR()
{
	int arr[10] = { 9,1,3,5,2,7,8,0,6,4 };
	SelectSort(arr, sizeof(arr) / sizeof(arr[0]));
	PrintArray(arr, sizeof(arr) / sizeof(arr[0]));
}

void TestCountSort()
{
	int arr[10] = { 9,1,3,5,2,7,8,0,6,4 };
	SelectSort(arr, sizeof(arr) / sizeof(arr[0]));
	PrintArray(arr, sizeof(arr) / sizeof(arr[0]));
}

void TestOP()
{
	srand((unsigned int)time(0));
	const int N = 1000000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);
	int* a7 = (int*)malloc(sizeof(int) * N);
	int* a8 = (int*)malloc(sizeof(int) * N);
	int* a9 = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
		a7[i] = a1[i];
		a8[i] = a1[i];
		a9[i] = a1[i];
	}

	int begin1 = clock();
	//InsertSort(a1, N);
	int end1 = clock();

	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();

	int begin3 = clock();
	//SelectSort(a3, N);
	int end3 = clock();

	int begin4 = clock();
	HeapSort(a4, N);
	int end4 = clock();

	int begin5 = clock();
	QuickSort(a5, 0, N - 1);
	int end5 = clock();

	int begin6 = clock();
	QuickSort1(a6, 0, N - 1);
	int end6 = clock();

	int begin7 = clock();
	QuickSortNonR(a7, 0, N - 1);
	int end7 = clock();

	int begin8 = clock();
	MergeSort(a8, N);
	//MergeSortNonR(a8, N);
	int end8 = clock();

	int begin9 = clock();
	CountSort(a9, N);
	int end9 = clock();

	printf("InsertSort:%d\n", end1 - begin1);
	printf("ShellSort:%d\n", end2 - begin2);
	printf("SelectSort:%d\n", end3 - begin3);
	printf("HeapSort:%d\n", end4 - begin4);
	printf("QuickSort:%d\n", end5 - begin5);
	printf("QuickSort1:%d\n", end6 - begin6);
	printf("QuickSortNonR:%d\n", end7 - begin7);
	printf("MergeSort:%d\n", end8 - begin8);
	printf("CountSort:%d\n", end9 - begin9);

	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
	free(a7);
	free(a8);
	free(a9);
}

int main()
{
	//TestInsertSort();
	//TestShellSort();
	//TestBubbleSort();
	//TestHeapSort();
	//TestSelectSort();
	//TestQuickSort();
	//TestQuickSort1();
	//TestQuickSortNonR();
	//TestMergeSort();
	//TestMergeSortNonR();
	//TestCountSort();
	TestOP();
	return 0;
}