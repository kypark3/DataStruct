#include <stdio.h>
#include "BinarySearchTree2.h"

int main( ) {

	BTreeNode *bst;
	BSTMakeAndInit(&bst);

	BSTInsert(&bst, 5); BSTInsert(&bst, 8);
	BSTInsert(&bst, 1); BSTInsert(&bst, 6);
	BSTInsert(&bst, 4); BSTInsert(&bst, 9);
	BSTInsert(&bst, 3);	BSTInsert(&bst, 2);
	BSTInsert(&bst, 7);

	BSTShowAll(bst); printf("\n");

	BTreeNode *sNode;
	sNode = BSTRemove(&bst, 3);
	if (sNode == NULL) printf("찾는 대상이 없음..\n");
	free(sNode);
	BSTShowAll(bst); printf("\n");

	sNode = BSTRemove(&bst, 8);
	if (sNode == NULL) printf("찾는 대상이 없음..\n");
	free(sNode);
	BSTShowAll(bst); printf("\n");

	sNode = BSTRemove(&bst, 1);
	if (sNode == NULL) printf("찾는 대상이 없음..\n");
	free(sNode);
	BSTShowAll(bst); printf("\n");

	sNode = BSTRemove(&bst, 10);
	if (sNode == NULL) printf("찾는 대상이 없음..\n");
	free(sNode);
	BSTShowAll(bst); printf("\n");

	return 0;
}