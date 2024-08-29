#include "Person.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
int GetSSN(Person *p) {
	return p->ssn;
}

void ShowPerInfo(Person *p) {
	printf("주민등록번호 : %d\n", p->ssn);
	printf("이름 : %s\n", p->name);
	printf("주소 : %s\n\n", p->addr);
}

Person* MakePersonData(int ssn, char *name, char *addr) {
	Person *newPerson = (Person*)malloc(sizeof(Person));
	newPerson->ssn = ssn;
	strcpy(newPerson->name, name);
	strcpy(newPerson->addr, addr);
	return newPerson;
}
