#include "Q06-1stack.h"
#include "Q06-1.h"
#include <stdio.h>
#include <stdlib.h>

void StackInit(Stack *stack) {
	stack->list = (List*)malloc(sizeof(List));
	ListInit(stack->list);
}

int SIsEmpty(Stack *stack) {
	if (LCount(stack->list) == 0) return TRUE;
	else return FALSE;
}

void SPush(Stack *stack, Data data) {
	LInsertFront(stack->list, data);
}

Data SPop(Stack *stack) {
	Data data;
	LFirst(stack->list, &data);
	LRemove(stack->list);
	return data;
}

Data SPeek(Stack *stack) {
	Data data;
	LFirst(stack->list, &data);
	return data;
}