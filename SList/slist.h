#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SLTNode;

//打印
void SLTPrint(SLTNode* phead);
//动态申请一个节点
SLTNode* BuySListNode(SLTDataType x);
//尾插
void SLTPushBack(SLTNode** pphead, SLTDataType x);
//头插
void SLTPushFront(SLTNode** pphead, SLTDataType x);
//尾删
void SLTPopBack(SLTNode** pphead);
//头删
void SLTPopFront(SLTNode** pphead);
//查找
SLTNode* SLTFind(SLTNode* phead, SLTDataType x);
//在pos之前插入x
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);
//在pos以后插入x
void SLTInsertAfter(SLTNode* pos, SLTDataType x);
//删除pos位置
void SLTErase(SLTNode** pphead, SLTNode* pos);
//删除pos的后一个位置
void SLTEraseAfter(SLTNode* pos);
//销毁链表
void SLTDestroy(SLTNode** pphead);