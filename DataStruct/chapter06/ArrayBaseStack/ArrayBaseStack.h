#ifndef __ARRAYBASESTACK_H__
#define __ARRAYBASESTACK_H__

#define TRUE	1
#define FALSE	0
#define STACK_LEN	100

typedef int Data;

typedef struct _arrayStack {
	Data stackArr[STACK_LEN];
	int topIndex;
}ArrayStack;

typedef ArrayStack Stack;

void StackInit(Stack *stack);
int SIsEmpty(Stack *stack);

void SPush(Stack *stack, Data data);
Data SPop(Stack *stack);
Data SPeek(Stack *stack);

#endif