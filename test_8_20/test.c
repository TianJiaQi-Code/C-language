//����������ʵ��ջ
typedef struct
{
    Que q1;//����1
    Que q2;//����2
} MyStack;

//���ٿռ䲢��ʼ��
MyStack* myStackCreate()
{
    MyStack* pst = (MyStack*)malloc(sizeof(MyStack));
    QueueInit(&pst->q1);
    QueueInit(&pst->q2);
    return pst;
}

//��Ԫ��xѹ��ջ��
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

//�Ƴ�������ջ��Ԫ��
int myStackPop(MyStack* obj)
{
    Que* empty = &obj->q1;
    Que* nonEmpty = &obj->q2;
    if (!QueueEmpty(&obj->q1))
    {
        nonEmpty = &obj->q1;
        empty = &obj->q2;
    }
    //ǰsize-1������ն���
    while (QueueSize(nonEmpty) > 1)
    {
        QueuePush(empty, QueueFront(nonEmpty));
        QueuePop(nonEmpty);
    }
    //�þֲ�������¼ջ��Ԫ�أ����㷵��
    int top = QueueFront(nonEmpty);
    QueuePop(nonEmpty);
    return top;
}

//����ջ��Ԫ��
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

//���ջ�ǿյģ�����true�����򣬷���false
bool myStackEmpty(MyStack* obj)
{
    return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

//����ջ
void myStackFree(MyStack* obj)
{
    QueueDestroy(&obj->q1);
    QueueDestroy(&obj->q2);
    free(obj);
}