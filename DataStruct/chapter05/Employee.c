#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#pragma warning(disable:4996)

void SetEmp(Employee *emp,char name[], int _Enum) {

	emp->name = (char*)malloc(sizeof(char) * (strlen(name)+1) );
	strcpy(emp->name, name);
	emp->Enum = _Enum;

}


void ShowInfo(Employee **pemp) {
	if (*pemp != NULL) {
		printf("�̸� : %s\n", (*pemp)->name);
		printf("��� : %d\n", (*pemp)->Enum);
	}
	else {
		printf("none\n");
	}
}

