#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

void ListInit(List *plist) {
	plist->head = (Node*)malloc(sizeof(Node));
	if (plist->head != NULL) {
		plist->head->next = NULL;
	
		plist->comp = NULL;
		plist->numOfData = 0;
	}
}
void LInsert(List *plist, LData data) {
	Node * newNode = (Node*)malloc(sizeof(Node));
	if (newNode != NULL) {
		newNode->data = data;
		newNode->next = plist->head->next;// NULL;

		plist->head->next = newNode;
		(plist->numOfData)++;
	}
}

int LFirst(List *plist, LData *pdata) {

	if (plist->head->next == NULL) {
		return FALSE;
	}

	plist->before = plist->head;
	plist->cur = plist->head->next;

	*pdata = plist->cur->data;
	return TRUE;
}
int LNext(List *plist, LData *pdata) {

	if (plist->cur->next == NULL) {
		return FALSE;
	}
	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return TRUE;
}

LData LRemove(List *plist) {
	if (plist->cur != NULL) {
		Node *rpos = plist->cur;
		LData rdata = rpos->data;

		plist->before->next = plist->cur->next;
		plist->cur = plist->before;
		free(rpos);

		(plist->numOfData)--;
		return rdata;
	}
}

int LCount(List *plist) {
	return plist->numOfData;
}

void SetSortRule(List *plist, int(*comp)(LData d1, LData d2)) {
	if (comp != NULL) {
		plist->comp = comp;
	}
}

void SInsert(List *plist, LData data) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	if (newNode != NULL) {
		newNode->data = data;
	
		Node *pred = plist->head;
		while (pred->next != NULL && plist->comp(data, pred->next->data) != 0) {
			pred = pred->next;
		}
		newNode->next = pred->next;
		pred->next = newNode;
	
		(plist->numOfData)++;
	}
}
