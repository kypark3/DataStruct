#include "Table2.h"
#include "DLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

void TBLInit(Table *tbl, HashFunc *hf) {

	for (int i = 0; i < MAX_TBL; i++) {
		ListInit(&(tbl->tbl[i]));
	}

	tbl->hf = hf;
}

void TBLInsert(Table *tbl, Key k, Value v) {
	int hv = tbl->hf(k);
	Slot ns = { k, v };

	if (TBLSearch(tbl, k) != NULL) {
		printf("키 중복 오류\n");
		return;
	}
	else {
		LInsert(&(tbl->tbl[hv]), ns);
	}
}

Value TBLDelete(Table *tbl, Key k) {
	int hv = tbl->hf(k);
	Slot cSlot;

	if (LFisrt(&(tbl->tbl[hv]), &cSlot)) {
		
		if (cSlot.key == k) {
			LRemove(&(tbl->tbl[hv]));
			return cSlot.val;
		}
		else {
			while (LNext(&(tbl->tbl[hv]), &cSlot)) {
				if (cSlot.key == k) {
					LRemove(&(tbl->tbl[hv]));
					return cSlot.val;
				}
			}
		}
	}
	
	return NULL;
}

Value TBLSearch(Table *tbl, Key k) {

	int hv = tbl->hf(k);
	Slot cSlot;

	if (LFisrt(&(tbl->tbl[hv]), &cSlot)) {

		if (cSlot.key == k) {
			return cSlot.val;
		}
		else {
			while (LNext(&(tbl->tbl[hv]), &cSlot)) {
				if (cSlot.key == k) {
					return cSlot.val;
				}
			}
		}
	}

	return NULL;
}