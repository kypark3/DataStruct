#include <stdio.h>
#include "DequeBaseQueue.h"
// ���Լ���

void QueueInit(Queue *q) {
	DequeInit(q);
}

int QIsEmpty(Queue *q) {
	if (DQIsEmpty(q)) return TRUE;
	else return FALSE;
}

void Enqueue(Queue *q, Data data) {
	DQAddLast(q, data);
}

Data Dequeue(Queue *q) {
	DQRemoveFisrt(q);
}

Data QPeek(Queue *q) {
	return DQGetFirst(q);
}