#ifndef __BDLINKEDLIST_H__
#define __BDLINKEDLIST_H__

#define FALSE	0;
#define TRUE	1;

typedef int Data;
typedef struct _node {
	Data data;
	struct _node *next;
	struct _node *prev;

}Node;


typedef struct _DLinkedList {
	Node *head;
	Node *tail;
	Node *cur;
	int numOfData;

}DBLinkedList;

typedef DBLinkedList List;

void ListInit(List *list);
void LInsert(List *list, Data data); // 꼬리에노드를 추가.

int LFisrt(List *list, Data *data);
int LNext(List *list, Data *data);
int LPrevious(List *list, Data *data);

Data LRemove(List *list);
int LCount(List *list);

#endif // !__BDLINKEDLIST_H__
