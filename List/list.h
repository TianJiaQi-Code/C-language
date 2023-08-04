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

//����һ���½ڵ�
LTNode* BuyLTNode(LTDataType x);
//��ʼ��
LTNode* LTInit();
//��ӡ
void LTPrint(LTNode* phead);
//β��
void LTPushBack(LTNode* phead, LTDataType x);
//βɾ
void LTPopBack(LTNode* phead);
//ͷ��
void LTPushFront(LTNode* phead, LTDataType x);
//ͷɾ
void LTPopFront(LTNode* phead);
//����������
int LTSize(LTNode* phead);
//����
LTNode* LTFind(LTNode* phead, LTDataType x);
//��posǰ����
void LTInsert(LTNode* pos, LTDataType x);
//ɾ��posλ�õĽڵ�
void LTErase(LTNode* pos);