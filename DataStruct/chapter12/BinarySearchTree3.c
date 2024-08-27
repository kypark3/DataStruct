#include "BinarySearchTree3.h"
#include "AVLRebalnce.h"
#include <stdio.h>
#include <stdlib.h>

void BSTMakeAndInit(BTreeNode **root) {
	*root = NULL;
}

BSTData BSTGetNodeData(BTreeNode *bst) {
	if (bst != NULL) {
		return GetData(bst);
	}
}

BTreeNode* BSTInsert(BTreeNode **root, BSTData data) {

	/* 반한형 void
	
	- 문제점 : 완벽한 벨런싱을 하지 못함  , 
	  이유 : 모든 부모노드를 확인하지 않기때문
	
	ex) 4에서 밸런싱 필요함.
	  3
	 2 4
	1   5
	     6

	BTreeNode *pNode = NULL;
	BTreeNode *cNode = *root;

	while (cNode != NULL)
	{
		if (GetData(cNode) == data) {
			return;
		}

		pNode = cNode;

		if (data < GetData(cNode)) {
			cNode = GetLeftSubTree(cNode);
		}
		else {
			cNode = GetRightSubTree(cNode);
		}
	}

	BTreeNode *nNode = MakeBTreeNode( );
	SetData(nNode, data);

	if (pNode == NULL) {
		(*root) = nNode;
	}
	else {

		if (data < GetData(pNode)) {
			MakeLeftSubTree(pNode, nNode);
		}
		else {
			MakeRightSubTree(pNode, nNode);
		}
	}

	(*root) = Rebalance(root);
	*/
	
	/*
	 - 해결 : 부모노드를 기준으로 리벨런싱을 한다.
	*/

	if (*root == NULL) {
		*root = MakeBTreeNode( );
		SetData(*root, data);
	}
	else if (data < GetData(*root)) {
		BSTInsert(&(*root)->left,data);
		(*root) = Rebalance(root);
	}
	else if (data > GetData(*root)) {
		BSTInsert(&(*root)->right, data);
		(*root) = Rebalance(root);
	}
	else {
		return NULL;
	}

	return *root;
}

BTreeNode* BSTSearch(BTreeNode *bst, BSTData target) {

	BTreeNode *cNode = bst;
	BSTData cd;

	while(bst != NULL){
		cd = GetData(cNode);

		if (cd == target) {
			return cNode;
		}
		else if (cd < target){
			cNode = GetLeftSubTree(cNode);
		}
		else {
			cNode = GetRightSubTree(cNode);
		}
	}

	return NULL;
}

BTreeNode* BSTRemove(BTreeNode **root, BSTData target) {

	BTreeNode *vNode = MakeBTreeNode( );
	BTreeNode *pNode = vNode;
	BTreeNode *cNode = *root;

	ChangeRightSubTree(vNode, *root);

	while (cNode != NULL && GetData(cNode) != target)
	{
		pNode = cNode;

		if (target < GetData(cNode)) {
			cNode = GetLeftSubTree(cNode);
		}
		else {
			cNode = GetRightSubTree(cNode);
		}
	}

	if (cNode == NULL) return NULL;

	BTreeNode *dNode = cNode;
	// 단말
	if (GetLeftSubTree(cNode) == NULL && GetRightSubTree(cNode) == NULL) {

		if (GetLeftSubTree(pNode) == cNode) {
			RemoveLeftSubTree(pNode);
		}
		else {
			RemoveRightSubTree(pNode);
		}
	}
	// 한쪽만 있는 경우
	else if (GetLeftSubTree(cNode) == NULL || GetRightSubTree(cNode) == NULL) {

		BTreeNode *dcNode;

		if (GetLeftSubTree(dNode) != NULL) {
			dcNode = GetLeftSubTree(dNode);
		}
		else {
			dcNode = GetRightSubTree(dNode);
		}

		if (GetLeftSubTree(pNode) == dNode) {
			ChangeLeftSubTree(pNode, dcNode);
		}
		else {
			ChangeRightSubTree(pNode, dcNode);
		}
	}
	// 두쪽다 있는 경우
	else {

		BTreeNode *mNode = GetRightSubTree(cNode); 
		BTreeNode *mpNode = cNode;

		while (GetLeftSubTree(mNode) != NULL) {
			mpNode = mNode;
			mNode = GetLeftSubTree(mNode);
		}

		BTData delData = GetData(dNode);
		SetData(dNode, GetData(mNode));

		if (GetLeftSubTree(mpNode) == mNode) {
			ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
		}
		else {
			ChangeRightSubTree(mpNode, GetRightSubTree(mNode));
		}

		dNode = mNode;
		SetData(dNode, delData);
	}

	if (GetRightSubTree(vNode) != (*root) ) {
		(*root) = GetRightSubTree(vNode);
	}

	free(vNode);
	(*root) = Rebalance(*root);
	return dNode;
}

void ShowBSTData(BSTData data) {
	printf("%d ", data);
}

void BSTShowAll(BTreeNode *bst) {
	InorderTraverse(bst, ShowBSTData);
}