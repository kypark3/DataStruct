#include <stdio.h>
#pragma warning(disable:4996)

typedef struct _empInfo {
	int empNum;
	int age;
}EmpInfo;

int main( ) {
	EmpInfo empInfoArr[1000];
	EmpInfo ei;
	int eNum;

	printf("����� ���� �Է� :");
	scanf("%d %d", &(ei.empNum), &(ei.age));
	empInfoArr[ei.empNum] = ei;

	printf("Ȯ���ϰ��� ������ ����Է� : ");
	scanf("%d", &eNum);

	ei = empInfoArr[eNum];
	printf("��� %d , ���� %d \n", ei.empNum, ei.age);

	return 0;
}