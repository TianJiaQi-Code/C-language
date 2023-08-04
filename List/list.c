#include "list.h"

//����һ���½ڵ�
LTNode* BuyLTNode(LTDataType x)
{
	LTNode* node = (LTNode*)malloc(sizeof(LTNode));
	if (node == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	node->data = x;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

//��ʼ�������һ���ڱ�λ��
LTNode* LTInit()
{
	LTNode* phead = BuyLTNode(0);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}

//��ӡ
void LTPrint(LTNode* phead)
{
	assert(phead);
	printf("phead <==> ");
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d <==> ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

//β��
void LTPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTInsert(phead, x);
}

//βɾ
void LTPopBack(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);
	LTErase(phead->prev);
}

//ͷ��
void LTPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTInsert(phead->next, x);
}

//ͷɾ
void LTPopFront(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);
	LTErase(phead->next);
}

//����������
int LTSize(LTNode* phead)
{
	assert(phead);
	int size = 0;
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		size++;
		cur = cur->next;
	}
	return size;
}

//��posǰ����
void LTInsert(LTNode* pos, LTDataType x)
{
	assert(pos);
	LTNode* posPrev = pos->prev;
	LTNode* newnode = BuyLTNode(x);
	posPrev->next = newnode;
	newnode->prev = posPrev;
	newnode->next = pos;
	pos->prev = newnode;
}

//ɾ��posλ�õĽڵ�
void LTErase(LTNode* pos)
{
	assert(pos);
	LTNode* posPrev = pos->prev;
	LTNode* posNext = pos->next;
	free(pos);
	posPrev->next = posNext;
	posNext->prev = posPrev;
}

//����
LTNode* LTFind(LTNode* phead, LTDataType x)
{
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

//��������
void LTDestroy(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		LTNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(phead);
}