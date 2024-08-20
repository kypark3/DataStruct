#ifndef  __DEQUEBASEQUEUE_H__
#define __DEQUEBASEQUEUE_H__

#include "Deque.h"

typedef Deque Queue;

void QueueInit(Queue *q);
int QIsEmpty(Queue *q);
void Enqueue(Queue *q, Data data);
Data Dequeue(Queue *q);
Data QPeek(Queue *q);

#endif // ! __DEQUEBASEQUEUE_H__
