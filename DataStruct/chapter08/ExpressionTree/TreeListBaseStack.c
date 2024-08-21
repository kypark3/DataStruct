#include "TreeListBaseStack.h"
#include <stdio.h>
#include <stdlib.h>
//후입선출
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
	
	if (SIsEmpty(stack)) {
		printf("stack is empty\n");
		exit(-1);
	}
	Data retdata = stack->head->data;
	Node *delNode = stack->head;
	
	stack->head = stack->head->next;
	free(delNode);

	return retdata;
}

Data SPeek(Stack *stack) {

	if (SIsEmpty(stack)) {
		printf("stack is empty\n");
		exit(-1);
	}

	return stack->head->data;
}
