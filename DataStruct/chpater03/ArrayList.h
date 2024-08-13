#ifndef __ARRAYLIST_H__
#define __ARRAYLIST_H__

#include "Point.h"
#include "NameCard.h"
#define TRUE 1
#define FALSE 0
#define LIST_LEN 100

//typedef Point* LData;
typedef NameCard* LData;

typedef struct __ArrayList {
	LData arr[LIST_LEN];
	int numOfData;
	int curPosition;

} ArrayList;

typedef ArrayList List;

void ListInit(List *list);
void LInsert(List *list, LData data);

int LFirst(List *list, LData *pdata);
int LNext(List *list, LData *pdata);

LData LRemove(List *list);
int LCount(List *list);

#endif