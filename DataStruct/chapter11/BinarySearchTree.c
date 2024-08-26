#include "BinarySearchTree.h"
#include <stdio.h>
#include <stdlib.h>

void BSTMakeAndInit(BTreeNode **root){
	*root = NULL;
}

BSTData BSTGetNodeData(BTreeNode *bst) {
	return GetData(bst);
}

void BSTInsert(BTreeNode **root, BSTData data) {
	BTreeNode *pNode = NULL;
	BTreeNode *cNode = *root;

	while (cNode != NULL) {

		if (data == GetData(cNode)) {
			return ; // 데이터의 중복 허용하지 않음.
		}

		pNode = cNode;

		if (GetData(cNode) > data) {
			cNode = GetLeftSubTree(cNode);
		}
		else {
			cNode = GetRightSubTree(cNode);
		}
	}

	BTreeNode *nNode = MakeBTreeNode( );
	SetData(nNode, data);

	if (pNode == NULL) { // 부모노드라면
		(*root) = nNode;
	}
	else {

		if (data < GetData(pNode) ) {
			MakeLeftSubTree(pNode, nNode);
		}
		else {
			MakeRightSubTree(pNode, nNode);
		}
	}

}

BTreeNode* BSTSearch(BTreeNode *bst, BSTData target) {

	BTreeNode *cNode = bst;
	BSTData cd;

	while (cNode != NULL) {

		cd = GetData(cNode);

		if (target == cd) {
			return cNode;
		}
		else if (target < cd) {
			cNode = GetLeftSubTree(cNode);
		}
		else {
			cNode = GetRightSubTree(cNode);
		}
	}

	return NULL; // 탐색대상이 저장되어 있지 않음.
}
