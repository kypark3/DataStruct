#ifndef __LISTBASEQUEUE_H__
#define __LISTBASEQUEUE_H__

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node {
	Data data;
	struct _node *next;
}Node;

typedef struct _LQueue {
	Node *front;
	Node *rear;
}LQueue;

typedef LQueue Queue;

void QueueInit(Queue *q);
int QIsEmpty(Queue *q);

void Enqueue(Queue *q, Data data);
Data Dequeue(Queue *q);
Data QPeek(Queue *q);

#endif // !__LISTBASEQUEUE_H__
