#include "Deque.h"
#include <stdlib.h>
#include <stdio.h>

void DequeInit(Deque *dq) {
	dq->head = NULL;
	dq->tail = NULL;
}

int DQIsEmpty(Deque *dq) {
	if (dq->head == NULL) return 1;
	else return 0;
}

void DQAddFirst(Deque *dq, Data data) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	if (newNode != NULL) {
		newNode->data = data;

		newNode->next = dq->head;
		
		if (DQIsEmpty(dq)) {
			dq->tail = newNode;
		}
		else {
			dq->head->prev = newNode;
		}
		newNode->prev = NULL;
		dq->head = newNode;
	}
}

void DQAddLast(Deque *dq, Data data) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	if (newNode != NULL) {
		newNode->data = data;

		newNode->prev = dq->tail;

		if (DQIsEmpty(dq)) {
			dq->head = newNode;
		}
		else {
			dq->tail->next = newNode;
		}
		
		newNode->next = NULL;
		dq->tail = newNode;
	}
}

Data DQRemoveFisrt(Deque *dq) {
	Node *rnode = dq->head;
	if (DQIsEmpty(dq)) {
		printf("Deque is empty\n");
		exit(-1);
	}
	Data rdata = rnode->data;

	dq->head = dq->head->next;
	free(rnode);

	if (dq->head == NULL) {
		dq->tail = NULL;
	}
	else {
		dq->head->prev = NULL;
	}

	return rdata;
}

Data DQRemoveLast(Deque *dq) {
	Node *rnode = dq->tail;
	if (DQIsEmpty(dq)) {
		printf("Deque is empty\n");
		exit(-1);
	}
	Data rdata = rnode->data;

	dq->tail = dq->tail->prev;
	free(rnode);

	if (dq->tail == NULL) {
		dq->head = NULL;
	}
	else {
		dq->tail->next = NULL;
	}
	return rdata;
}

Data DQGetFirst(Deque *dq) {
	if (DQIsEmpty(dq)) {
		printf("Deque is empty\n");
		exit(-1);
	}

	return dq->head->data;
}

Data DQGetLst(Deque *dq) {
	if (DQIsEmpty(dq)) {
		printf("Deque is empty\n");
		exit(-1);
	}

	return dq->tail->data;
}
