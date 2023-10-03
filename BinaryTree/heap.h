#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}HP;

// 向上调整
void AdjustUp(HPDataType* a, int child);
// 向下调整
void AdjustDown(HPDataType* a, int n, int parent);
// 交换
void Swap(HPDataType* p1, HPDataType* p2);
// 打印堆
void HeapPrint(HP* php);
// 堆的初始化
void HeapInit(HP* php);
// 堆的初始化（数组）
void HeapInitArray(HP* php, int* a, int n);
// 堆的销毁
void HeapDestroy(HP* php);
// 堆的插入
void HeapPush(HP* php, HPDataType x);
// 堆的删除
void HeapPop(HP* php);
// 取堆顶的数据
HPDataType HeapTop(HP* php);
// 堆的判空
bool HeapEmpty(HP* php);