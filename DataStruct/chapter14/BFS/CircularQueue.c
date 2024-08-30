#include "CircularQueue.h"
#include <stdio.h>
#include <stdlib.h>

void QueueInit(Queue *pq) {
	pq->front = 0;
	pq->rear = 0;
}

int QIsEmpty(Queue *pq) {
	if (pq->front == pq->rear) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

int NextPosIdx(int pos) {
	if (pos == QUE_LEN - 1 ) return 0;
	else return pos + 1;
}

void EnQueue(Queue *pq, Data data) {
	if (NextPosIdx(pq->rear) == pq->front) {
		printf("Queue is empty\n");
		exit(-1);
	}
	pq->rear = NextPosIdx(pq->rear);
	pq->queArr[pq->rear] = data;
}

Data DeQueue(Queue *pq) {

	if (QIsEmpty(pq)) {
		printf("Queue is Empty\n");
		exit(-1);
	}

	pq->front = NextPosIdx(pq->front);
	return pq->queArr[pq->front];
}

Data QPeek(Queue *pq) {
	if (QIsEmpty(pq)) {
		printf("Queue is empty\n");
		exit(-1);
	}

	return pq->queArr[NextPosIdx(pq->front)];
}
