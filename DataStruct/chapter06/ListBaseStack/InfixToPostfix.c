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
		if (isdigit(tok)) { //숫자라면 convExp 차례로저장
			convExp[idx++] = tok;
		}
		else { // 연산자라면?
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
					// 스택이 비어있지 않고 
					// 스택 가장 꼭대기에 있는 문자가 연산자와 비교햇을때 우선순위가 같거나(0) 클때(1)
					convExp[idx++] = SPop(&stack);
				}
				SPush(&stack, tok); // 중위수식에있는 연산자가 스택에 쌓임
				break;
			}
		}
	}

	while (!SIsEmpty(&stack)) { // 스택이 비어있지 않을때까지 전부 pop
		convExp[idx++] = SPop(&stack);
	}

	strcpy(exp, convExp); // exp로 복사
	free(convExp);
}