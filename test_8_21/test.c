typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
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
		//������
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