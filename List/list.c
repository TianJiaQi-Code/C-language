#include "list.h"

//创建一个新节点
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

//初始化（添加一个哨兵位）
LTNode* LTInit()
{
	LTNode* phead = BuyLTNode(0);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}

//打印
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

//尾插
void LTPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTInsert(phead, x);
}

//尾删
void LTPopBack(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);
	LTErase(phead->prev);
}

//头插
void LTPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTInsert(phead->next, x);
}

//头删
void LTPopFront(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);
	LTErase(phead->next);
}

//计算链表长度
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

//在pos前插入
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

//删除pos位置的节点
void LTErase(LTNode* pos)
{
	assert(pos);
	LTNode* posPrev = pos->prev;
	LTNode* posNext = pos->next;
	free(pos);
	posPrev->next = posNext;
	posNext->prev = posPrev;
}

//查找
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

//销毁链表
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