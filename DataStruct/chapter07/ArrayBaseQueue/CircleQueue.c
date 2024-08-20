#include "CircleQueue.h"
#include <stdio.h>
#include <stdlib.h>

void QueueInit(Queue *q) {
	q->front = 0;
	q->rear = 0;
}
int QIsEmpty(Queue *q) {
	 return q->front == q->rear;
}

int NextPosIdx(int pos) {
	if (pos == QUE_LEN - 1) return 0;
	else return pos + 1;
}

void Enqueue(Queue *q, Data data) {
	if (NextPosIdx(q->rear) == q->front) {
		printf("Queue is full\n");
		exit(-1);
	}
	q->rear = NextPosIdx(q->rear);
	q->queArr[q->rear] = data;
}

Data Dequeue(Queue *q) {
	if (QIsEmpty(q)) {
		printf("Queue is empty\n");
		exit(-1);
	}
	q->front = NextPosIdx(q->front);
	return q->queArr[q->front];
}

Data QPeek(Queue *q) {
	if (QIsEmpty(q)) {
		printf("Queue is empty\n");
		exit(-1);
	}
	return q->queArr[NextPosIdx(q->front)];
}