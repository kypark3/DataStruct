#include "Person.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
int GetSSN(Person *p) {
	return p->ssn;
}

void ShowPerInfo(Person *p) {
	printf("�ֹε�Ϲ�ȣ : %d\n", p->ssn);
	printf("�̸� : %s\n", p->name);
	printf("�ּ� : %s\n\n", p->addr);
}

Person* MakePersonData(int ssn, char *name, char *addr) {
	Person *newPerson = (Person*)malloc(sizeof(Person));
	newPerson->ssn = ssn;
	strcpy(newPerson->name, name);
	strcpy(newPerson->addr, addr);
	return newPerson;
}
