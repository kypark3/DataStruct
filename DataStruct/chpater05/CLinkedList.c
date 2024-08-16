#include "CLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

void ListInit(List *plist) {
	plist->numOfData = 0;
	plist->cur = NULL;
	plist->before = NULL;
	plist->tail = NULL;
}

void LInsertFront(List *plist, Data data) { // 앞에서 넣기
	Node *newNode = (Node*)malloc(sizeof(Node));
	if (newNode != NULL) {
		newNode->data = data;
		if (plist->tail == NULL) {
			plist->tail = newNode;
			newNode->next = newNode;
		}
		else {
			newNode->next = plist->tail->next;
			plist->tail->next = newNode;
		}
		(plist->numOfData)++;
	}
}

void LInsert(List *plist, Data data) { // 뒤에서 넣기
	Node *newNode = (Node*)malloc(sizeof(Node));
	if (newNode != NULL) {
		newNode->data = data;
		if (plist->tail == NULL) {
			plist->tail = newNode;
			newNode->next = newNode;
		}
		else {
			newNode->next = plist->tail->next;
			plist->tail->next = newNode;
			plist->tail = newNode;
		}
		(plist->numOfData)++;
	}
}

int LFirst(List *plist, Data *pdata) {
	if (plist->tail == NULL) {
		return FALSE;
	}

	plist->before = plist->tail;
	plist->cur = plist->tail->next;
	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(List *plist, Data *pdata) {
	if (plist->tail == NULL) {
		return FALSE;
	}

	plist->before = plist->cur;
	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;
	return TRUE;
}

Data LRemove(List *plist) {
	Node *rpos = plist->cur;
	Data rdata = rpos->data;
 
	if (rpos == plist->tail) {
		if (plist->tail == plist->tail->next) {
			plist->tail = NULL;
		}
		else {
			plist->tail = plist->before;
		}
	}

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	(plist->numOfData)--;
	return rdata;
}

int LCount(List *plist) {
	return plist->numOfData;
}