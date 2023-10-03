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

// ���ϵ���
void AdjustUp(HPDataType* a, int child);
// ���µ���
void AdjustDown(HPDataType* a, int n, int parent);
// ����
void Swap(HPDataType* p1, HPDataType* p2);
// ��ӡ��
void HeapPrint(HP* php);
// �ѵĳ�ʼ��
void HeapInit(HP* php);
// �ѵĳ�ʼ�������飩
void HeapInitArray(HP* php, int* a, int n);
// �ѵ�����
void HeapDestroy(HP* php);
// �ѵĲ���
void HeapPush(HP* php, HPDataType x);
// �ѵ�ɾ��
void HeapPop(HP* php);
// ȡ�Ѷ�������
HPDataType HeapTop(HP* php);
// �ѵ��п�
bool HeapEmpty(HP* php);