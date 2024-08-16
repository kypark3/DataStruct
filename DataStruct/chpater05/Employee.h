#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__

typedef struct employee {

	char *name;
	int Enum;

}Employee;

void SetEmp(Employee *emp,char name[], int _Enum);
void ShowInfo(Employee **pemp);
#endif
