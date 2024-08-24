#include "ListBaseQueue.h"
#include <stdio.h>
#include <stdlib.h>

void QueueInit(Queue *q) {
	q->front = NULL;
	q->rear = NULL;
}

int QIsEmpty(Queue *q) {
	if (q->front == NULL) return 1;
	else return 0;
}

void Enqueue(Queue *q, Data data) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	if (newNode != NULL) {
		newNode->data = data;
		newNode->next = NULL;
		if (QIsEmpty(q) {
			q->front = newNode;
			q->rear = newNode;
		}
		else {
			q->rear->next = newNode;
			q->rear = newNode;
		}

	}
}

Data Dequeue(Queue *q) {
	Node *delNode;
	Data retData;

	if (QIsEmpty(q)) {
		printf("Queue is empty\n");
		exit(-1);
	}
	delNode = q->front;
	retData = q->front->data;
	q->front = q->front->next;
	
	free(delNode);
	return retData;
}

Data QPeek(Queue *q) {
	if (QIsEmpty(q)) {
		printf("Queue is empty\n");
		exit(-1);
	}
	return q->front->data;
}

