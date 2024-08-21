#include <stdio.h>
#include "BinaryTree2.h"

void ShowIntData( );

int main( ) {

	BTreeNode *t1 = MakeBTreeNode( );
	BTreeNode *t2 = MakeBTreeNode( );
	BTreeNode *t3 = MakeBTreeNode( );
	BTreeNode *t4 = MakeBTreeNode( );
	BTreeNode *t5 = MakeBTreeNode( );
	BTreeNode *t6 = MakeBTreeNode( );

	SetData(t1, 1);
	SetData(t2, 2);
	SetData(t3, 3);
	SetData(t4, 4);
	SetData(t5, 5);
	SetData(t6, 6);


	/*
				  t1(1)
		 t2(2)			  t3(3)
	t4(4)    t5(5)			     t6(6)
	*/

	MakeLeftSubTree(t1, t2);
	MakeRightSubTree(t1, t3);
	MakeLeftSubTree(t2, t4);
	MakeRightSubTree(t2, t5);
	MakeRightSubTree(t3, t6);


	printf("전위 순회 : "); // 1 2 4 5 3 6
	PreorderTraverse(t1, ShowIntData);
	printf("\n");
	printf("중위 순회 : "); // 4 2 5 1 3 6
	InorderTraverse(t1, ShowIntData);
	printf("\n");
	printf("후위 순회 : "); // 4 5 2 6 3 1
	PostorderTraverse(t1, ShowIntData);
	printf("\n");


	DeleteTree(t1);
	return 0;
}

void ShowIntData(BTData data ) {
	printf("%d ", data);
}