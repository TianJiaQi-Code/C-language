#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//支持动态增长的栈
typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;//栈顶
	int capacity;//容量
}ST;

//初始化栈
void STInit(ST* ps);
//销毁栈
void STDestroy(ST* ps);
//入栈
void STPush(ST* ps, STDataType x);
//出栈
void STPop(ST* ps);
//获取栈顶元素
STDataType STTop(ST* ps);
//获取栈中有效元素个数
int STSize(ST* ps);
//检测栈是否为空，如果为空返回非零结果，如果不为空返回0
bool STEmpty(ST* ps);