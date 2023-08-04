#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int LTDataType;
typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDataType data;
}LTNode;

//创建一个新节点
LTNode* BuyLTNode(LTDataType x);
//初始化
LTNode* LTInit();
//打印
void LTPrint(LTNode* phead);
//尾插
void LTPushBack(LTNode* phead, LTDataType x);
//尾删
void LTPopBack(LTNode* phead);
//头插
void LTPushFront(LTNode* phead, LTDataType x);
//头删
void LTPopFront(LTNode* phead);
//计算链表长度
int LTSize(LTNode* phead);
//查找
LTNode* LTFind(LTNode* phead, LTDataType x);
//在pos前插入
void LTInsert(LTNode* pos, LTDataType x);
//删除pos位置的节点
void LTErase(LTNode* pos);