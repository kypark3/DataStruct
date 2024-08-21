#ifndef __TREELISTBASESTACK_H__
#define __TREELISTBASESTACK_H__

#define TRUE 1
#define FALSE 0

#include "TreeBinaryTree2.h"

typedef BTreeNode* Data;

typedef struct _node {
	Data data;
	struct _node *next;
}Node;

typedef struct _liststack {
	Node *head;
}ListStack;

typedef ListStack Stack;

void StackInit(Stack *stack);
int SIsEmpty(Stack *stack);

void SPush(Stack *stack, Data data);
Data SPop(Stack *stack);
Data SPeek(Stack *stack);



#endif // !__LISTBASESTACK_H__
