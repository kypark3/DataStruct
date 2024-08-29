#ifndef __TABLE2_H__
#define __TABLE2_H__

#include "Slot2.h"
#include "DLinkedList.h"

#define MAX_TBL 100

typedef int HashFunc(Key k);

typedef struct _table {

	List tbl[MAX_TBL];
	HashFunc *hf;

}Table;

void TBLInit(Table *tbl, HashFunc *hf);
void TBLInsert(Table *tbl, Key k, Value v);
Value TBLDelete(Table *tbl, Key k);
Value TBLSearch(Table *tbl, Key k);


#endif // ! __TABLE2_H__

