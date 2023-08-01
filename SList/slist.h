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

//��ӡ
void SLTPrint(SLTNode* phead);
//��̬����һ���ڵ�
SLTNode* BuySListNode(SLTDataType x);
//β��
void SLTPushBack(SLTNode** pphead, SLTDataType x);
//ͷ��
void SLTPushFront(SLTNode** pphead, SLTDataType x);
//βɾ
void SLTPopBack(SLTNode** pphead);
//ͷɾ
void SLTPopFront(SLTNode** pphead);
//����
SLTNode* SLTFind(SLTNode* phead, SLTDataType x);
//��pos֮ǰ����x
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);
//��pos�Ժ����x
void SLTInsertAfter(SLTNode* pos, SLTDataType x);
//ɾ��posλ��
void SLTErase(SLTNode** pphead, SLTNode* pos);
//ɾ��pos�ĺ�һ��λ��
void SLTEraseAfter(SLTNode* pos);
//��������
void SLTDestroy(SLTNode** pphead);