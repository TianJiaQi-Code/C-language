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

//初始化
void STInit(ST* ps);
//销毁
void STDestroy(ST* ps);
//插入
void STPush(ST* ps, STDataType x);
//删除
void STPop(ST* ps);
//返回栈顶元素
STDataType STTop(ST* ps);
//计算栈的元素个数
int STSize(ST* ps);
//判断栈是否为空
bool STEmpty(ST* ps);