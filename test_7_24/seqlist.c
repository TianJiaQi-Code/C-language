#include "seqlist.h"

//˳����ʼ��
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

//����˳���
void SLDestroy(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}

//��ӡ����
void SLPrint(SL* ps)
{
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

//��̬����
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

//β��
void SLPushBack(SL* ps, SLDataType x)
{
	SLCheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}

//βɾ
void SLPopBack(SL* ps)
{
	assert(ps->size > 0);
	ps->size--;
}

//ͷ��
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

//ͷɾ
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

// ��posλ�ò���x
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

// ɾ��posλ�õ�ֵ
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