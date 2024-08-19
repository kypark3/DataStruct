#include "ArrayBaseStack.h"
#include <stdio.h>

void StackInit(Stack *stack) {
	stack->topIndex = -1;
}

int SIsEmpty(Stack *stack) {
	if (stack->topIndex == -1) return TRUE;
	else return FALSE;
}

void SPush(Stack *stack, Data data) {
	(stack->topIndex)++;
	stack->stackArr[stack->topIndex] = data;
}

Data SPop(Stack *stack) {
	int rIdx;

	if (SIsEmpty(stack)) {
		printf("Stack is empty\n");
		exit(-1);
	}

	rIdx = stack->topIndex;
	(stack->topIndex)--;
	return stack->stackArr[rIdx];
}

Data SPeek(Stack *stack) {
	if (SIsEmpty(stack)) {
		printf("Stack is empty\n");
		exit(-1);
	}

	return stack->stackArr[stack->topIndex];
}