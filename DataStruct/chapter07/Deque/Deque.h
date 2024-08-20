#ifndef __DEQUE_H__
#define __DEQUE_H__

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node {
	Data data;
	struct _node *next;
	struct _node *prev;
}Node;

typedef struct _dlDeque {
	Node *head;
	Node *tail;
}DLDeque;

typedef DLDeque Deque;

void DequeInit(Deque *dq);
int DQIsEmpty(Deque *dq);

void DQAddFirst(Deque *dq, Data data);
void DQAddLast(Deque *dq, Data data);

Data DQRemoveFisrt(Deque *dq);
Data DQRemoveLast(Deque *dq);

Data DQGetFirst(Deque *dq);
Data DQGetLst(Deque *dq);
#endif // !__DEQUE_H__
