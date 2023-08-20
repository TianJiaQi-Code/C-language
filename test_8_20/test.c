//用两个队列实现栈
typedef struct
{
    Que q1;//队列1
    Que q2;//队列2
} MyStack;

//开辟空间并初始化
MyStack* myStackCreate()
{
    MyStack* pst = (MyStack*)malloc(sizeof(MyStack));
    QueueInit(&pst->q1);
    QueueInit(&pst->q2);
    return pst;
}

//将元素x压入栈顶
void myStackPush(MyStack* obj, int x)
{
    if (!QueueEmpty(&obj->q1))
    {
        QueuePush(&obj->q1, x);
    }
    else
    {
        QueuePush(&obj->q2, x);
    }
}

//移除并返回栈顶元素
int myStackPop(MyStack* obj)
{
    Que* empty = &obj->q1;
    Que* nonEmpty = &obj->q2;
    if (!QueueEmpty(&obj->q1))
    {
        nonEmpty = &obj->q1;
        empty = &obj->q2;
    }
    //前size-1个导入空队列
    while (QueueSize(nonEmpty) > 1)
    {
        QueuePush(empty, QueueFront(nonEmpty));
        QueuePop(nonEmpty);
    }
    //用局部变量记录栈顶元素，方便返回
    int top = QueueFront(nonEmpty);
    QueuePop(nonEmpty);
    return top;
}

//返回栈顶元素
int myStackTop(MyStack* obj)
{
    if (!QueueEmpty(&obj->q1))
    {
        return QueueBack(&obj->q1);
    }
    else
    {
        return QueueBack(&obj->q2);
    }
}

//如果栈是空的，返回true；否则，返回false
bool myStackEmpty(MyStack* obj)
{
    return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

//销毁栈
void myStackFree(MyStack* obj)
{
    QueueDestroy(&obj->q1);
    QueueDestroy(&obj->q2);
    free(obj);
}