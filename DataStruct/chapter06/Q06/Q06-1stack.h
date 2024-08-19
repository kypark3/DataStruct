#ifndef __Q061STACK_H__
#define __Q061STACK_H__

#include "Q06-1.h"

typedef struct listbasestack {
	List *list;
}ListBaseStack;

typedef ListBaseStack Stack;

void StackInit(Stack *stack);
int SIsEmpty(Stack *stack);
void SPush(Stack *stack, Data data);
Data SPop(Stack *stack);
Data SPeek(Stack *stack);

#endif // !_Q06-1STACK_H__

