#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//֧�ֶ�̬������ջ
typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;//ջ��
	int capacity;//����
}ST;

//��ʼ��ջ
void STInit(ST* ps);
//����ջ
void STDestroy(ST* ps);
//��ջ
void STPush(ST* ps, STDataType x);
//��ջ
void STPop(ST* ps);
//��ȡջ��Ԫ��
STDataType STTop(ST* ps);
//��ȡջ����ЧԪ�ظ���
int STSize(ST* ps);
//���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0
bool STEmpty(ST* ps);