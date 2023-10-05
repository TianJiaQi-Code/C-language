#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//链式结构：表示队列
typedef int QDataType;
typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QNode;

//队列的结构
typedef struct Queue
{
	QNode* head;
	QNode* tail;
	int size;
}Que;

//初始化队列
void QueueInit(Que* pq);
//销毁队列
void QueueDestroy(Que* pq);
//队尾入队列
void QueuePush(Que* pq, QDataType x);
//队头出队列
void QueuePop(Que* pq);
//获取队列头部元素
QDataType QueueFront(Que* pq);
//获取队列队尾元素
QDataType QueueBack(Que* pq);
//检测队列是否为空，如果为空返回非零结果，如果非空返回0
bool QueueEmpty(Que* pq);
//获取队列中有效元素个数
int QueueSize(Que* pq);