#ifndef __DLINKEDLIST_H__
#define __DLINKEDLIST_H__

#define TRUE 1
#define FALSE 0

typedef int LData;

typedef struct _node {
	LData data;
	struct _node *next;
}Node;

typedef struct _linkedlist {
	Node *head;
	Node *cur;
	Node *before;
	int numOfData;
	int (*comp)(LData d1, LData d2);
}LinkedList;

typedef LinkedList List;

void ListInit(List *list);
void Linsert(List *list, LData data);
int LFirst(List *list, LData *pdata);
int LNext(List *list, LData *pdata);
LData LRemove(List *list);
int LCount(List *list);
void SetSortRule(List *list, int(*comp)(LData d1, LData d2));

#endif // !__DLINKEDLIST_H__
