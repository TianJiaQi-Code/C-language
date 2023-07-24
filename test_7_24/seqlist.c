#include "seqlist.h"

//顺序表初始化
void SLInit(SL* ps)
{
	ps->a = (SLDataType*)malloc(sizeof(SLDataType) * 4);
	if (ps->a == NULL)
	{
		perror("malloc failed");
		exit(-1);
	}
	ps->size = 0;
	ps->capacity = 4;
}

//销毁顺序表
void SLDestroy(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}

//打印数据
void SLPrint(SL* ps)
{
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

//动态扩容
void SLCheckCapacity(SL* ps)
{
	if (ps->size == ps->capacity)
	{
		SLDataType* tmp = realloc(ps->a, ps->capacity * 2 * (sizeof(SLDataType)));
		if (tmp == NULL)
		{
			perror("realloc failed");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity *= 2;
	}
}

//尾插
void SLPushBack(SL* ps, SLDataType x)
{
	SLCheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}

//尾删
void SLPopBack(SL* ps)
{
	assert(ps->size > 0);
	ps->size--;
}

//头插
void SLPushFront(SL* ps, SLDataType x)
{
	SLCheckCapacity(ps);
	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		--end;
	}
	ps->a[0] = x;
	ps->size++;
}

//头删
void SLPopFront(SL* ps)
{
	assert(ps->size > 0);
	int start = 0;
	while (start < ps->size - 1)
	{
		ps->a[start] = ps->a[start + 1];
		++start;
	}
	ps->size--;
}

// 在pos位置插入x
void SLInsert(SL* ps, int pos, SLDataType x)
{
	SLCheckCapacity(ps);
	int end = ps->size - 1;
	while (end >= pos - 1)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[pos - 1] = x;
	ps->size++;
}

// 删除pos位置的值
void SLErase(SL* ps, int pos)
{
	assert(ps->size > 0);
	int start = pos - 1;
	while (start < ps->size - 1)
	{
		ps->a[start] = ps->a[start + 1];
		start++;
	}
	ps->size--;
}