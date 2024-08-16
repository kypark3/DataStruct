#include "BDLinkedList.h"
#include <stdio.h>


int main( ) {
	List list;
	ListInit(&list);
	int data;

	LInsert(&list, 1);
	LInsert(&list, 2);
	LInsert(&list, 3);
	LInsert(&list, 4);
	LInsert(&list, 5);
	LInsert(&list, 6);
	LInsert(&list, 7);
	LInsert(&list, 8);

	if (LFisrt(&list, &data)) {
		printf("%d ", data);

		while (LNext(&list, &data)) {
			printf("%d ", data);
		}

		while (LPrevious(&list, &data)) {
			printf("%d ", data);
		}
		printf("\n\n");
	}

	if (LFisrt(&list, &data)) {
		if (data % 2 == 0) {
			LRemove(&list);
		}
		while (LNext(&list, &data)) {
			if (data % 2 == 0) {
				LRemove(&list);
			}
		}
	}

	if (LFisrt(&list, &data)) {
		printf("%d ", data);

		while (LNext(&list, &data)) {
			printf("%d ", data);
		}

		printf("\n\n");
	}

	return 0;
}

