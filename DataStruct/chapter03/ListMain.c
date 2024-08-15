#include <stdio.h>
#include "ArrayList.h"

int main( ) {


	List list;
	ListInit(&list);
	LData data;
	int sum = 0;

	for (int i = 1; i <= 9; i++) {
		LInsert(&list, i);
	}


	if (LFisrt(&list, &data)) {
		sum += data;

		while (LNext(&list, &data)) {
			sum += data;
		}
	}
	printf("저장된 list의 값의 합 : %d\n", sum);

	if (LFisrt(&list, &data)) {
		if (data % 2 == 0 || data % 3 == 0) {
			LRemove(&list);
		}

		while (LNext(&list, &data)) {
			if (data % 2 == 0 || data % 3 == 0) {
				LRemove(&list);
			}
		}
	}

	if (LFisrt(&list, &data)) {
		printf("%d ", data);

		while (LNext(&list, &data)) {
			printf("%d ", data);
		}
	}
	printf("\n\n");

	return 0;
}