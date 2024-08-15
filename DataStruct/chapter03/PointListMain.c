#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"
#include "Point.h"

int main( ) {
	List list;
	ListInit(&list);
	Point *point;

	point = (Point*)malloc(sizeof(Point));
	SetPointPos(point, 2, 1);
	LInsert(&list, point);

	point = (Point*)malloc(sizeof(Point));
	SetPointPos(point, 2, 2);
	LInsert(&list, point);

	point = (Point*)malloc(sizeof(Point));
	SetPointPos(point, 3, 1);
	LInsert(&list, point);

	point = (Point*)malloc(sizeof(Point));
	SetPointPos(point, 3, 2);
	LInsert(&list, point);

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