#ifndef __TABLE_H__
#define __TABLE_H__

#include "Slot.h"

#define MAX_TBL 100
typedef int HashFunc(Key k);

typedef struct _table {
	Slot tbl[MAX_TBL];
	HashFunc *hf;
}Table;

void TBInit(Table *t, HashFunc *f);
void TBLInsert(Table *t, Key k, Value v);

Value TBLDelet(Table *t, Key k);
Value TBLSerch(Table *t, Key k);


#endif // !__TABLE_H__
