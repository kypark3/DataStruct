#include "Person.h"
#include "Table2.h"

#include <stdio.h>
#include <stdlib.h>

int MyHashFunc(int k) {
	return k % 100;
}

int main( ) {

	Table myTbl;
	Person *np;
	Person *sp;
	Person *rp;

	TBLInit(&myTbl, MyHashFunc);

	np = MakePersonData(900254, "park1", "addr1");
	TBLInsert(&myTbl, GetSSN(np), np);

	np = MakePersonData(900139, "park2", "addr2");
	TBLInsert(&myTbl, GetSSN(np), np);

	np = MakePersonData(900827, "park3", "addr3");
	TBLInsert(&myTbl, GetSSN(np), np);

	//Å½»ö
	sp = TBLSearch(&myTbl, 900254);
	if (sp != NULL) ShowPerInfo(sp);

	sp = TBLSearch(&myTbl, 900139);
	if (sp != NULL) ShowPerInfo(sp);

	sp = TBLSearch(&myTbl, 900827);
	if (sp != NULL) ShowPerInfo(sp);

	//»èÁ¦

	rp = TBLDelete(&myTbl, 900254);
	if (rp != NULL) free(rp);

	rp = TBLDelete(&myTbl, 900139);
	if (rp != NULL) free(rp);

	rp = TBLDelete(&myTbl, 900827);
	if (rp != NULL) free(rp);
	return 0;

}