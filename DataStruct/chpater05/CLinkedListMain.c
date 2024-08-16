#include "CLinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"
#include <string.h>
#pragma warning(disable:4996)

Employee *WhoIsNightDuty(List *plist, char name[], int day);

int main( ) {
	
	List list;
	ListInit(&list);
	Employee *emp;

	emp = (Employee*)malloc(sizeof(Employee));
	SetEmp(emp, "pky1", 1111);
	LInsert(&list, emp);

	emp = (Employee*)malloc(sizeof(Employee));
	SetEmp(emp, "pky2", 2222);
	LInsert(&list, emp);

	emp = (Employee*)malloc(sizeof(Employee));
	SetEmp(emp, "pky3", 3333);
	LInsert(&list, emp);

	emp = (Employee*)malloc(sizeof(Employee));
	SetEmp(emp, "pky4", 4444);
	LInsert(&list, emp);

	if (LFirst(&list, &emp)) {
		ShowInfo(&emp);
		for (int i = 0; i < LCount(&list) - 1; i++) {
			if (LNext(&list, &emp)) {
				ShowInfo(&emp);
			}
		}
	}
	printf("\n");

	emp = WhoIsNightDuty(&list, "pky1", 3);
	ShowInfo(&emp);

	emp = WhoIsNightDuty(&list, "pky4", 15);
	ShowInfo(&emp);
	printf("\n");


	//free
	if (LFirst(&list, &emp)) {
		free(emp->name);
		free(emp);
		for (int i = 0; i < LCount(&list) - 1; i++) {
			if (LNext(&list, &emp)) {
				free(emp->name);
				free(emp);
			}
		}
	}
	
	/*
	List list;
	ListInit(&list);
	int data, i, nodeNum;
	
	LInsertFront(&list, 2);
	LInsertFront(&list, 1);
	LInsert(&list, 3);
	LInsert(&list, 4);
	LInsert(&list, 5);
	

	if (LFirst(&list, &data)) {
		printf("%d ", data);

		for (i = 0; i < 3 * LCount(&list) - 1; i++) {
			if (LNext(&list, &data)) {
				printf("%d ", data);
			}
		}
	}
	printf("\n");
	
	nodeNum = LCount(&list);

	if (nodeNum != 0) {

		if (LFirst(&list, &data)) {
			if (!(data % 2)) {
				LRemove(&list);
			}
		}

		for (i = 0; i < nodeNum - 1; i++) {
			LNext(&list, &data);
			if (!(data % 2)) {
				LRemove(&list);
			}
		}
	}

	if (LFirst(&list, &data)) {
		printf("%d ", data);

		for (i = 0; i < LCount(&list) - 1; i++) {
			if (LNext(&list, &data)) {
				printf("%d ", data);
			}
		}
	}
	printf("\n");
	*/

	return 0;
}

Employee *WhoIsNightDuty(List *plist, char name[], int day) {

	int i;
	int empCnt = LCount(plist);
	Employee *NDemp;

	LFirst(plist, &NDemp);

	if (strcmp(NDemp->name, name)) {

		for (i = 0; empCnt - 1; i++) {
			LNext(plist, &NDemp);

			if (strcmp(NDemp->name, name)) {
				break;
			}
		}
		if (i >= empCnt - 1) return NULL;
	}

	for (i = 0; i < day; i++) {
		LNext(plist, &NDemp);
	}

	return NDemp;
}