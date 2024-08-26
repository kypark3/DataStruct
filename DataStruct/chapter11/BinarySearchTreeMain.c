#include "BinarySearchTree.h"
#include <stdio.h>

int main( ) {
	BTreeNode *bstRoot;
	BTreeNode *sNode; //search Node

	BSTMakeAndInit(&bstRoot);

	BSTInsert(&bstRoot, 9);
	BSTInsert(&bstRoot, 1);
	BSTInsert(&bstRoot, 6);
	BSTInsert(&bstRoot, 2);
	BSTInsert(&bstRoot, 8);
	BSTInsert(&bstRoot, 3);
	BSTInsert(&bstRoot, 5);

	/*
	    9
	  1	   
	    6    
	  2   8 
	   3
	    5
	*/

	sNode = BSTSearch(bstRoot, 4);
	if (sNode == NULL) {
		printf("Å½»ö ½ÇÆÐ\n");
	}
	else {
		printf("Å½»ö ¼º°ø Å°°ª : %d\n", BSTGetNodeData(sNode));
	}



	return 0;
}