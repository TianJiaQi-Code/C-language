typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
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

void STInit(ST* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->capacity = 0;
	ps->top = 0;
}

void STDestroy(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = 0;
	ps->top = 0;
}

void STPush(ST* ps, STDataType x)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STDataType* tmp = (STDataType*)realloc(ps->a, sizeof(STDataType) * newCapacity);
		if (tmp == NULL)
		{
			perror("realloc fail");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newCapacity;
	}
	ps->a[ps->top] = x;
	ps->top++;
}

void STPop(ST* ps)
{
	assert(ps);
	assert(ps->top > 0);
	ps->top--;
}

STDataType STTop(ST* ps)
{
	assert(ps);
	assert(ps->top > 0);
	return ps->a[ps->top - 1];
}

int STSize(ST* ps)
{
	assert(ps);
	return ps->top;
}

bool STEmpty(ST* ps)
{
	assert(ps);
	return ps->top == 0;
}

//=======================================================================

typedef struct
{
	ST pushst;
	ST popst;
} MyQueue;


MyQueue* myQueueCreate()
{
	MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
	STInit(&obj->pushst);
	STInit(&obj->popst);
	return obj;
}

void myQueuePush(MyQueue* obj, int x)
{
	STPush(&obj->pushst, x);
}

int myQueuePeek(MyQueue* obj)
{
	if (STEmpty(&obj->popst))
	{
		//捯数据
		while (!STEmpty(&obj->pushst))
		{
			STPush(&obj->popst, STTop(&obj->pushst));
			STPop(&obj->pushst);
		}
	}
	return STTop(&obj->popst);
}

int myQueuePop(MyQueue* obj)
{
	int front = myQueuePeek(obj);
	STPop(&obj->popst);
	return front;
}

bool myQueueEmpty(MyQueue* obj)
{
	return STEmpty(&obj->popst) && STEmpty(&obj->pushst);
}

void myQueueFree(MyQueue* obj)
{
	STDestroy(&obj->popst);
	STDestroy(&obj->pushst);
	free(obj);
}