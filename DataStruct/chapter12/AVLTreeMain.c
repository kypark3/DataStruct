#include <stdio.h>
#include "BinaryTree3.h"
#include "BinarySearchTree3.h"

int main( ) {
	BTreeNode *avlRoot;
	BSTMakeAndInit(&avlRoot);
	BTreeNode *clNode;
	BTreeNode *crNode;
	/*
	-- RR --
	BSTInsert(&avlRoot, 1);
	BSTInsert(&avlRoot, 2);
	BSTInsert(&avlRoot, 3);
	BSTInsert(&avlRoot, 4);
	
	printf("root Node : %d\n", GetData(avlRoot));
	clNode = GetLeftSubTree(avlRoot);
	crNode = GetRightSubTree(avlRoot);
	printf("哭率 1: %d , 坷弗率 1: %d", GetData(clNode), GetData(crNode));
	*/

	/*
	-- LL -- 
		BSTInsert(&avlRoot, 5);
	BSTInsert(&avlRoot, 2);
	BSTInsert(&avlRoot, 1);

	printf("root Node : %d\n", GetData(avlRoot));
	clNode = GetLeftSubTree(avlRoot);
	crNode = GetRightSubTree(avlRoot);
	printf("哭率 1: %d , 坷弗率 1: %d", GetData(clNode), GetData(crNode));
	*/

	/*
	-- LR --
	BSTInsert(&avlRoot, 5);
	BSTInsert(&avlRoot, 2);
	BSTInsert(&avlRoot, 4);

	printf("root Node : %d\n", GetData(avlRoot));
	clNode = GetLeftSubTree(avlRoot);
	crNode = GetRightSubTree(avlRoot);
	printf("哭率 1: %d , 坷弗率 1: %d", GetData(clNode), GetData(crNode));
	*/

	/*
	-- RL --
	*/
	BSTInsert(&avlRoot, 2);
	BSTInsert(&avlRoot, 5);
	BSTInsert(&avlRoot, 4);

	printf("root Node : %d\n", GetData(avlRoot));
	clNode = GetLeftSubTree(avlRoot);
	crNode = GetRightSubTree(avlRoot);
	printf("哭率 1: %d , 坷弗率 1: %d", GetData(clNode), GetData(crNode));

	return 0;
}