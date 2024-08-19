#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"


void StackInit(Stack *stack) {
	stack->head = NULL;
}
int SIsEmpty(Stack *stack) {
	if (stack->head == NULL) return TRUE;
	else return FALSE;
}

void SPush(Stack *stack, Data data) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	if (newNode != NULL) {
		newNode->data = data;
		newNode->next = stack->head;
		stack->head = newNode;
	}
}
Data SPop(Stack *stack) {
	Data rdata;
	Node *rnode;

	if (SIsEmpty(stack)) {
		printf("Stack is empty\n");
		exit(-1);
	}

	rdata = stack->head->data;
	rnode = stack->head;

	stack->head = stack->head->next;
	free(rnode);

	return rdata;
}

Data SPeek(Stack *stack) {

	if (SIsEmpty(stack)) {
		printf("Stack is empty\n");
		exit(-1);
	}

	return stack->head->data;
}