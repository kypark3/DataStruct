#include <stdio.h>
#include <stdlib.h>
#include "Person.h"
#include "Table.h"

int MyHashFunc(int k) {
	return k % 100;
}


int main( ) {

	Table myTbl;
	Person *np;
	Person *sp;
	Person *rp;
	TBInit(&myTbl, MyHashFunc);

	np = MakePersonData(20120003, "park1", "addr1");
	TBLInsert(&myTbl, GetSSN(np), np);

	sp = MakePersonData(20130012, "park2", "addr2");
	TBLInsert(&myTbl, GetSSN(sp), sp);

	rp = MakePersonData(20170049, "park3", "addr3");
	TBLInsert(&myTbl, GetSSN(rp), rp);

	sp = TBLSerch(&myTbl, 20120003);
	if (sp != NULL) ShowPerInfo(sp);

	sp = TBLSerch(&myTbl, 20130012);
	if (sp != NULL) ShowPerInfo(sp);

	sp = TBLSerch(&myTbl, 20170049);
	if (sp != NULL) ShowPerInfo(sp);

	rp = TBLDelet(&myTbl, 20120003);
	if (rp != NULL) free(rp);

	rp = TBLDelet(&myTbl, 20130012);
	if (rp != NULL) free(rp);

	rp = TBLDelet(&myTbl, 20170049);
	if (rp != NULL) free(rp);



	return 0;
}