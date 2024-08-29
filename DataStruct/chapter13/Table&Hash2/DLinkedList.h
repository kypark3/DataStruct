#ifndef __DLINKEDLIST_H__
#define __DLINKEDLIST_H__

#define TRUE 1
#define FALSE 0

#include "Slot2.h"

typedef Slot LData;

typedef struct _node {
	LData data;
	struct _node *next;
}Node;

typedef struct _linkedList {
	Node *head;
	Node *cur;
	Node *before;
	int numOfData;
	int (*comp)(LData d1, LData d2);
}LinkedList;

typedef LinkedList List;

void ListInit(List *plist);
void LInsert(List *plist, LData data);
void SInsert(List *plist, LData data);
int LFisrt(List *plist, LData *pdata);
int LNext(List *plist, LData *pdata);

LData LRemove(List *plist);
int LCount(List *plist);

void SetSortRule(List *plist, int (*comp)(LData d1, LData d2));

#endif // !__DLINKEDLIST_H__
