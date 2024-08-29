#include "DLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

void ListInit(List *list) {
	list->head = (Node*)malloc(sizeof(Node));
	list->head->next = NULL;
	list->comp = NULL;
	list->numOfData = 0;
}

void Finsert(List *list, LData data) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = list->head->next;
	list->head->next = newNode;
	list->numOfData++;
}

void Sinsert(List *list, LData  data) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	
	Node *cNode = list->head;
	while (cNode->next != NULL && list->comp(data, cNode->data) != 0) {
		cNode = cNode->next;
	}
	newNode->next = cNode->next;
	cNode->next = newNode;
	list->numOfData++;
}

void Linsert(List *list, LData data) {
	if (list->comp == NULL) {
		Finsert(list, data);
	}
	else {
		Sinsert(list, data);
	}
}

int LFirst(List *list, LData *pdata) {
	if (list->head->next == NULL) return FALSE;

	list->before = list->head;
	list->cur = list->head->next;

	*pdata = list->cur->data;
	return TRUE;

}

int LNext(List *list, LData *pdata) {
	if (list->cur->next == NULL) return FALSE;

	list->before = list->cur;
	list->cur = list->cur->next;
	*pdata = list->cur->data;
	return TRUE;
}

LData LRemove(List *list) {
	if (list->cur != NULL) {
		Node *rNode = list->cur;
		LData retData = rNode->data;

		list->before->next = list->cur->next;
		list->cur = list->before;
		free(rNode);

		list->numOfData--;
		return retData;
	}
}

int LCount(List *list) {
	return list->numOfData;
}

void SetSortRule(List *list, int(*comp)(LData d1, LData d2)) {
	list->comp = comp;
}
