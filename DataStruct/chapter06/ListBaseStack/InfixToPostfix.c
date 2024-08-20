#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "InfixToPostfix.h"
#include "ListBaseStack.h"
#pragma warning(disable:4996)

int GetOpPrec(char op) {

	switch (op) {
	case '*':
	case '/':
		return 5;
	case '-':
	case '+':
		return 3;
	case '(':
		return 1;
	}
	return -1;
}

int WhoPrecOp(char op1, char op2) {
	int op1Prec = GetOpPrec(op1);
	int op2Prec = GetOpPrec(op2);

	if (op1Prec > op2Prec) return 1;
	else if (op1Prec < op2Prec) return -1;
	else return 0;
}

void ConvToRPNExp(char exp[]) {
	Stack stack;
	
	int expLen = strlen(exp);
	char *convExp = (char*)malloc(expLen + 1);

	int i, idx = 0;
	char tok, popOp;

	if (convExp != NULL) {
		memset(convExp, 0, sizeof(char) * expLen + 1);
	}
	StackInit(&stack);


	for (i = 0; i < expLen; i++) {
		tok = exp[i];
		if (isdigit(tok)) { //���ڶ�� convExp ���ʷ�����
			convExp[idx++] = tok;
		}
		else { // �����ڶ��?
			switch (tok) {
			case '(':
				SPush(&stack, tok);
				break;

			case ')':
				while (1) {
					popOp = SPop(&stack);
					if (popOp == '(') {
						break;
					}
					convExp[idx++] = popOp;
				}
				break;
			
			case'+': case'-': case'*': case'/':
				while (!SIsEmpty(&stack) && WhoPrecOp(SPeek(&stack), tok) >= 0) {  
					// ������ ������� �ʰ� 
					// ���� ���� ����⿡ �ִ� ���ڰ� �����ڿ� �������� �켱������ ���ų�(0) Ŭ��(1)
					convExp[idx++] = SPop(&stack);
				}
				SPush(&stack, tok); // �������Ŀ��ִ� �����ڰ� ���ÿ� ����
				break;
			}
		}
	}

	while (!SIsEmpty(&stack)) { // ������ ������� ���������� ���� pop
		convExp[idx++] = SPop(&stack);
	}

	strcpy(exp, convExp); // exp�� ����
	free(convExp);
}