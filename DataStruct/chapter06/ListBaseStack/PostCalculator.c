#include "PostCalculator.h"
#include <string.h>
#include <ctype.h>
#include "ListBaseStack.h"

int EvalRPNExp(char exp[]) {

	Stack stack;
	int expLen = strlen(exp);
	int i;
	char tok, op1, op2;
	
	StackInit(&stack);

	for (i = 0; i < expLen; i++) {
		tok = exp[i];

		if (isdigit(tok)) { // 정수면 문자상태이므로 정수로 바꿔서 push
			SPush(&stack, tok -'0');
		}
		else { // 연산자이면 정수두개를 pop
			op2 = SPop(&stack);
			op1 = SPop(&stack);

			switch (tok) {
			case'*':
				SPush(&stack, op1 * op2);
				break;
			case'/':
				SPush(&stack, op1 / op2);
				break;
			case'+':
				SPush(&stack, op1 + op2);
				break;
			case'-':
				SPush(&stack, op1 - op2);
				break;
			}
		}
	}

	return SPop(&stack);
}
