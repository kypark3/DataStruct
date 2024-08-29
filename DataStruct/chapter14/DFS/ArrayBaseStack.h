#ifndef __ARRAYBASESTACK_H__
#define __ARRAYBASESTACK_H__

#define TRUE 1
#define FALSE 0
#define STACK_LEN 100
#include "DLinkedList.h"

typedef LData Data;

typedef struct _stack {
	Data stackArr[STACK_LEN];
	int topIndex;
}ArrayStack;

typedef ArrayStack Stack;

void StackInit(Stack *pstack);
int SIsEmpty(Stack *pstack);

void SPush(Stack *pstack, Data data);
Data SPop(Stack *pstack);
Data SPeek(Stack *pstack);

#endif // !__ARRAYBASESTACK_H__
