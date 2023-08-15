typedef struct
{
    Que q1;
    Que q2;
} MyStack;


MyStack* myStackCreate()
{
    MyStack* pst = (MyStack*)malloc(sizeof(MyStack));
    QueueInit(&pst->q1);
    QueueInit(&pst->q2);
}

void myStackPush(MyStack* obj, int x)
{
    if (!QueueEmpty(&obj->q1));
    {
        QueuePush(&obj->q1, x);
    }
    else
    {
        QueuePush(&obj->p2, x);
    }
}

int myStackPop(MyStack* obj)
{
    Que* empty = &obj->q1;
    Que* nonEmpty = &obj->p2;
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
    int top = QueueFront(nonEmpty);
    QueuePop(nonEmpty);
    return top;
}

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

bool myStackEmpty(MyStack* obj)
{
    return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

void myStackFree(MyStack* obj)
{
    QueueDestroy(&obj->q1);
    QueueDestroy(&obj->q2);
    free(obj);
}