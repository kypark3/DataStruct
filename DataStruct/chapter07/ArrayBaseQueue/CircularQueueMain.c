#include "CircleQueue.h"
#include <stdio.h>

int main( ) {

	Queue q;
	QueueInit(&q);

	Enqueue(&q, 1);
	Enqueue(&q, 2);
	Enqueue(&q, 3);
	Enqueue(&q, 4);
	Enqueue(&q, 5);
	
	printf("%d ", q.queArr[0]);
	printf("%d ", q.queArr[1]);
	printf("%d ", q.queArr[2]);
	printf("%d ", q.queArr[3]);
	printf("%d ", q.queArr[4]);
	printf("%d \n\n\n", q.queArr[5]);

	Dequeue(&q); Dequeue(&q);
	printf("%d ",QPeek(&q));

	printf("%d ", q.queArr[0]);
	printf("%d ", q.queArr[1]);
	printf("%d ", q.queArr[2]);
	printf("%d ", q.queArr[3]);
	printf("%d ", q.queArr[4]);
	printf("%d \n\n\n", q.queArr[5]);

	while (!QIsEmpty(&q)) {
		printf("%d ", Dequeue(&q));
	}

	return 0;
}