#include <stdio.h>
#include "DLinkedList.h"

int WhoIsPrecede1(LData d1, LData d2) {
	if (d1 < d2) return 0;
	else return 1;
}


int main( ) {

	List list;
	LData data;
	ListInit(&list);

	SetSortRule(&list, WhoIsPrecede1);

	LInsert(&list, 33); 
	LInsert(&list, 22); 
	LInsert(&list, 22);
	LInsert(&list, 11); 
	LInsert(&list, 11); 
	
	SInsert(&list, 10);


	printf("현재 데이터 수 : %d\n", LCount(&list));

	if (LFirst(&list, &data)) {
		printf("%d ", data);
	
		while (LNext(&list, &data)) {
			printf("%d ", data);
		}
	}

	if (LFirst(&list, &data)) {

		if (data == 22) {
			LRemove(&list);
		}

		while (LNext(&list, &data)) {
			if (data == 22) {
				LRemove(&list);
			}
		}
	}
	printf("\n\n");

	printf("현재 데이터 수 : %d\n", LCount(&list));

	if (LFirst(&list, &data)) {
		printf("%d ", data);

		while (Lnext(&list, &data)) {
			printf("%d ", data);
		}
	}
	printf("\n\n");
	return 0;
}