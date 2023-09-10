#pragma once

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _a;
	int _size;
	int _capacity;
}Heap;

// 堆的构建
void HeapCreate(Heap* hp, HPDataType* a, int n);
// 堆的销毁

// 堆的插入

// 堆的删除

// 取堆顶的数据

// 堆的数据个数

// 堆的判空