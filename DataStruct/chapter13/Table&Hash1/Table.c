#include "Table.h"
#include <stdio.h>
#include <stdlib.h>

void TBInit(Table *t, HashFunc *f) {
	int i;
	for (i = 0; i < MAX_TBL; i++) {
		(t->tbl[i]).status = EMPTY;
	}
	t->hf = f;
}

void TBLInsert(Table *t, Key k, Value v){
	int hv = t->hf(k);
	t->tbl[hv].val = v;
	t->tbl[hv].key = k;
	t->tbl[hv].status = INUSE;
}

Value TBLDelet(Table *t, Key k) {
	int hv = t->hf(k);

	if ((t->tbl[hv]).status != INUSE) {
		return NULL;
	}
	else {
		(t->tbl[hv]).status = DELETED;
		return (t->tbl[hv]).val;
	}

}

Value TBLSerch(Table *t, Key k) {

	int hv = t->hf(k);
	if ((t->tbl[hv]).status != INUSE) {
		return NULL;
	}
	else {
		return (t->tbl[hv]).val;
	}

}
