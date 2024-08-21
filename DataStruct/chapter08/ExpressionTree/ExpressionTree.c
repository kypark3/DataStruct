#include "ExpressionTree.h"
#include "TreeListBaseStack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

BTreeNode* MakeExpTree(char exp[]) {
	Stack stack;
	StackInit(&stack);

	BTreeNode *node;
	int expLen = strlen(exp);
	int i;

	for (i = 0; i < expLen; i++) {
		node = MakeBTreeNode( );

		if (isdigit(exp[i])) { // 정수(피연산자)이면 
			SetData(node, exp[i] - '0');
		}
		else { // 연산자이면
			MakeRightSubTree(node, SPop(&stack));
			MakeLeftSubTree(node, SPop(&stack));
			SetData(node, exp[i]);
		}
		SPush(&stack, node);

	}

	return SPop(&stack); // root pop 
}

int EvaluateExpTree(BTreeNode *bt) {

	if (GetLeftSubTree(bt) == NULL && GetRightSubTree(bt) == NULL)
		return GetData(bt);

	int op1 = EvaluateExpTree(GetLeftSubTree(bt));
	int op2 = EvaluateExpTree(GetRightSubTree(bt));

	switch (GetData(bt)) {
	case '+':
		return op1 + op2;
	case '-':
		return op1 - op2;
	case '*':
		return op1 * op2;
	case '/':
		return op1 / op2;
	}

}

void ShowNodeData(BTData data) {
	if (0 <= data && data <= 9) {
		printf("%d ", data);
	}
	else {
		printf("%c ", data);
	}
}


void ShowPrefixTypeExp(BTreeNode *bt) {
	PreorderTraverse(bt, ShowNodeData);
}

void ShowInfixTypeExp(BTreeNode *bt) {

	if (bt == NULL) return;

	if (bt->left != NULL) {
		printf("( ");
	}

	ShowInfixTypeExp(bt->left);
	ShowNodeData(bt->data);
	ShowInfixTypeExp(bt->right);

	if (bt->right != NULL) {
		printf(") ");
	}

}

void ShowPostfixTypeExp(BTreeNode *bt) {
	PostorderTraverse(bt, ShowNodeData);
}
