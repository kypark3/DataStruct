#include "DLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

void ListInit(List *plist) {
	plist->head = (Node*)malloc(sizeof(Node));
	plist->head->next = NULL;
	plist->comp = NULL;
	plist->numOfData = 0;
}

void FInsert(List *plist, LData data) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	if (newNode != NULL) {
		newNode->data = data;
		newNode->next = plist->head->next;
		plist->head->next = newNode;
		(plist->numOfData)++;
	}
}

void SInsert(List *plist, LData data) {// 정렬기준이 있을때
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode != NULL) {
		
		Node *cNode = plist->head;
		newNode->data = data;
		while (cNode->next != NULL && plist->comp(data, cNode->next->data) != 0) {
			cNode = cNode->next;
		}

		newNode->next = cNode->next;
		cNode->next = newNode;
		(plist->numOfData)++;
	}
}

void LInsert(List *plist, LData data) {
	if (plist->comp == NULL) {
		FInsert(plist, data);
	}
	else {
		SInsert(plist, data);
	}
}

int LFirst(List *plist, LData *pdata) {
	if (plist->head->next == NULL) {
		return FALSE;
	}

	plist->befor = plist->head;
	plist->cur = plist->head->next;

	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(List *plist, LData *pdata) {

	if (plist->cur->next == NULL) {
		return FALSE;
	}

	plist->befor = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return TRUE;
}

LData LRemove(List *plist) {

	if (plist->cur != NULL) {
		Node *rNode = plist->cur;
		LData rdata = rNode->data;

		plist->befor->next = plist->cur->next;
		plist->cur = plist->befor;
		free(rNode);

		(plist->numOfData)--;
		return rdata;
	}

}

int LCount(List *plist) {
	return plist->numOfData;
}

void SetSortRule(List *plist, int(*comp)(LData d1, LData d2)) {
	plist->comp = comp;
}
