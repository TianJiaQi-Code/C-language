#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//��ʽ�ṹ����ʾ����
typedef int QDataType;
typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QNode;

//���еĽṹ
typedef struct Queue
{
	QNode* head;
	QNode* tail;
	int size;
}Que;

//��ʼ������
void QueueInit(Que* pq);
//���ٶ���
void QueueDestroy(Que* pq);
//��β�����
void QueuePush(Que* pq, QDataType x);
//��ͷ������
void QueuePop(Que* pq);
//��ȡ����ͷ��Ԫ��
QDataType QueueFront(Que* pq);
//��ȡ���ж�βԪ��
QDataType QueueBack(Que* pq);
//�������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0
bool QueueEmpty(Que* pq);
//��ȡ��������ЧԪ�ظ���
int QueueSize(Que* pq);