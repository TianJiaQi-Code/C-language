#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;

//��ʼ��
void STInit(ST* ps);
//����
void STDestroy(ST* ps);
//����
void STPush(ST* ps, STDataType x);
//ɾ��
void STPop(ST* ps);
//����ջ��Ԫ��
STDataType STTop(ST* ps);
//����ջ��Ԫ�ظ���
int STSize(ST* ps);
//�ж�ջ�Ƿ�Ϊ��
bool STEmpty(ST* ps);