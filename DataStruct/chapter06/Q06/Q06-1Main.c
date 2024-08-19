#include "Q06-1stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

int main( ) {

	Stack stack;
	StackInit(&stack);

	SPush(&stack, 1);
	SPush(&stack, 2);
	SPush(&stack, 3);
	SPush(&stack, 4);
	SPush(&stack, 5);

	while (!SIsEmpty(&stack)) {
		printf("%d ", SPop(&stack));
	}

	return 0;
}


//중위 - > 후위

/*
3 + 2 * 4 => 3 2 4 * +
2 * 4 + 3 => 2 4 * 3 +
2 * 1 + 3 / 2 => 2 1 * 3 2 / +

(1 * 2 + 3 ) / 4 => 1 2 * 3 4 /
(1 + 2 * 3 )

*/