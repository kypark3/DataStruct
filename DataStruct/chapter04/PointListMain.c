#include <stdio.h>
#include <stdlib.h>
#include "Point.h"
#include "DLinkedList.h"

int WhoIsPreced(LData p1, LData p2) {

	if (p1->xpos < p2->xpos) {
		return 0;
	}
	else if (p1->xpos == p2->xpos) {
		if (p1->ypos < p2->ypos)return 0;
		else return 1;
	}
	else {
		return 1;
	}
}

int main( ) {
	List list;
	ListInit(&list);
	Point *point;

	SetSortRule(&list, WhoIsPreced);


	point = (Point*)malloc(sizeof(Point));
	SetPointPos(point, 3, 2);
	LInsert(&list, point);

	point = (Point*)malloc(sizeof(Point));
	SetPointPos(point, 3, 1);
	LInsert(&list, point);

	point = (Point*)malloc(sizeof(Point));
	SetPointPos(point, 1, 3);
	LInsert(&list, point);

	point = (Point*)malloc(sizeof(Point));
	SetPointPos(point, 1, 1);
	LInsert(&list, point);
	
	point = (Point*)malloc(sizeof(Point));
	SetPointPos(point, 1, 2);
	SInsert(&list, point);

	point = (Point*)malloc(sizeof(Point));
	SetPointPos(point, 2, 4);
	SInsert(&list, point);

	printf("현재 데이터 수 : %d\n", LCount(&list));

	if (LFirst(&list, &point)) {
		ShowPointPos(point);
		while (LNext(&list, &point)) {
			ShowPointPos(point);
		}
	}

	Point compPos;
	compPos.xpos = 2;
	compPos.ypos = 0;

	if (LFirst(&list, &point)) {

		if (PointComp(point, &compPos) == 1) {
			point = LRemove(&list);
			free(point);
		}

		while (LNext(&list, &point)) {
			if (PointComp(point, &compPos) == 1) {
				point = LRemove(&list);
				free(point);
			}
		}
	}

	printf("현재 데이터 수 : %d\n", LCount(&list));
	if (LFirst(&list, &point)) {
		ShowPointPos(point);
		while (LNext(&list, &point)) {
			ShowPointPos(point);
		}
	}


	return 0;
}