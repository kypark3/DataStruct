#include <stdio.h>
#include "BinaryTree.h"

void InorderTraverse(BTreeNode *bt) {

	if (bt == NULL) return;

	InorderTraverse(bt->left);
	printf("%d ", bt->data);
	InorderTraverse(bt->right);
}

void PreorderTraverse(BTreeNode *bt) {

	if (bt == NULL) return;

	printf("%d ", bt->data);
	PreorderTraverse(bt->left);
	PreorderTraverse(bt->right);
}

void PostorderTraverse(BTreeNode *bt) {

	if (bt == NULL) return;

	PostorderTraverse(bt->left);
	PostorderTraverse(bt->right);
	printf("%d ", bt->data);
}

int main( ) {

	BTreeNode *t1 = MakeBTreeNode( );
	BTreeNode *t2 = MakeBTreeNode( );
	BTreeNode *t3 = MakeBTreeNode( );
	BTreeNode *t4 = MakeBTreeNode( );

	SetData(t1, 1);
	SetData(t2, 2);
	SetData(t3, 3);
	SetData(t4, 4);

	/*
			    t1(1)
		  t2(2)		  t3(3)
	t4(4)
	*/

	MakeLeftSubTree(t1, t2);
	MakeRightSubTree(t1, t3);
	MakeLeftSubTree(t2, t4);
	printf("중위 순회 : ");
	InorderTraverse(t1); // 4 2 1 3
	printf("\n");
	
	printf("전위 순회 : ");
	PreorderTraverse(t1); // 1 2 4 3
	printf("\n");
	
	printf("후위 순회 : ");
	PostorderTraverse(t1); // 4 2 3 1
	printf("\n");

	/*
	printf("%d\n", GetData(t1)); // root
	printf("%d\n", GetData(GetLeftSubTree(t1))); //root -> left
	printf("%d\n", GetData(GetRightSubTree(t1))); // root -> right
	printf("%d\n", GetData(GetLeftSubTree(GetLeftSubTree(t1)))); // root -> left ->left
	*/
	return 0;
}