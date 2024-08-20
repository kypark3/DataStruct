#include "ListBaseQueue.h"
#include <stdio.h>

int main( ) {
	Queue q;
	QueueInit(&q);

	Enqueue(&q, 1);
	Enqueue(&q, 2);
	Enqueue(&q, 3);
	Enqueue(&q, 4);
	Enqueue(&q, 5);
	// f         r
	// # 5 4 3 2 1
	
	printf("peek : %d\n", QPeek(&q));

	while (!QIsEmpty(&q)) {
		printf("%d ", Dequeue(&q));
	}

	return 0;
}