#include "stack.h"
#include "queue.h"

void StackTest()
{
	ST st;
	STInit(&st);
	STPush(&st, 1);
	STPush(&st, 2);
	STPush(&st, 3);
	STPush(&st, 4);
	STPush(&st, 5);

	printf("%d\n", STSize(&st));
	printf("%d\n", STTop(&st));

	while (!STEmpty(&st))
	{
		printf("%d ", STTop(&st));
		STPop(&st);
	}
	printf("\n");

	STDestroy(&st);
}

void QueueTest()
{
	Que q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);

	printf("%d\n", QueueSize(&q));
	printf("%d\n", QueueFront(&q));
	printf("%d\n", QueueBack(&q));

	while (!QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	printf("\n");
	printf("%d\n", QueueSize(&q));

	QueueDestroy(&q);
}

int main()
{
	//StackTest();
	QueueTest();
	return 0;
}