#include "ArrayList.h"

void ListInit(List *list) {
	list->curPosition = -1;
	list->numOfData = 0;
}

void LInsert(List *list, LData data) {

	if (list->curPosition >= LIST_LEN) {
		puts("insert error");
		return;
	}
	list->arr[list->numOfData] = data;
	(list->numOfData)++;
}

int LFirst(List *list, LData *pdata) {
	if (list->numOfData == 0) {
		return FALSE;
	}
	list->curPosition = 0;
	*pdata = list->arr[0];
	return TRUE;
}

int LNext(List *list, LData *pdata) {
	if (list->curPosition >= list->numOfData - 1) {
		return FALSE;
	}

	(list->curPosition)++;
	*pdata = list->arr[list->curPosition];
	return TRUE;
}

LData LRemove(List *list) {

	int rpos = list->curPosition;
	int num = list->numOfData;

	int i;
	LData rdata = list->arr[rpos];

	for (i = rpos; i < num - 1; i++) {
		list->arr[i] = list->arr[i + 1];
	}
	(list->numOfData)--;
	(list->curPosition)--;
	return rdata;
}

int LCount(List *list) {
	return list->numOfData;
}

