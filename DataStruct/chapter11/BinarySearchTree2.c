#include "BinarySearchTree2.h"
#include <stdio.h>
#include <stdlib.h>

void BSTMakeAndInit(BTreeNode **root) {
	(*root) = NULL;
}

BSTData BSTGetNodeData(BTreeNode *bst) {
	return GetData(bst);
}

void BSTInsert(BTreeNode **root, BSTData data) {
	
	BTreeNode *pNode = NULL;
	BTreeNode *cNode = *root;

	while (cNode != NULL) {
		if (data == GetData(cNode)) {
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

	BTreeNode *nNode = MakeBtreeNode( );
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
}

BTreeNode* BSTSearch(BTreeNode *bst, BSTData target) {

	BTreeNode *cNode = bst;
	BSTData cd;

	while (cNode != NULL) {

		cd = GetData(bst);

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
	return NULL;
}

BTreeNode* BSTRemove(BTreeNode **root, BSTData target) {
	BTreeNode *Vroot = MakeBtreeNode( ); 
	// 가상 노드는 부모노드를 다른 노드와 함께 일반화 하기 위함.
	BTreeNode *pNode = Vroot;
	BTreeNode *cNode = *root;
	BTreeNode *dNode;

	ChangeRightSubTree(Vroot, *root);

	// 삭제 대상노드를 탐색
	while (cNode != NULL && GetData(cNode) != target){
		pNode = cNode;

		if (target < GetData(cNode)) {
			cNode = GetLeftSubTree(cNode);
		}
		else {
			cNode = GetRightSubTree(cNode);
		}
	}

	if (cNode == NULL) return NULL; // 삭제 대상이 존재하지 않을경우 NULL반환

	dNode = cNode; // 삭제대상을 dNode가 가르킴.

	//삭제 시작
	// 1. 단말 노드인경우
	if (GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL) {

		if (GetLeftSubTree(pNode) == dNode) {
			RemoveLeftSubTree(pNode);
		}
		else {
			RemoveRightSubTree(pNode);
		}

	}
	// 2. 삭제할 노드의 자식노드가 한개만 있는 경우
	else if (GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL) {

		BTreeNode *dcNode; // 삭제 대상의 자식노드를 가르킴
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
	// 3. 삭제할 노드의 자식노드가 두개다 있는 경우
	else {
		BTreeNode *mNode = GetRightSubTree(dNode); //대체 노드 (데이터가 바뀔 노드)
		BTreeNode *mpNode = dNode;
		BTData delData;

		while (GetLeftSubTree(mNode) != NULL) { // 왼쪽 끝까지 가서 최소값을 찾음.
			mNode = mpNode;
			mpNode = GetLeftSubTree(mNode);
		}

		delData = GetData(dNode); // 대체전 데이터 백업
		SetData(dNode, GetData(mNode)); // 삭제될 노드에 대체할 노드의 데이터를 대입

		if (GetLeftSubTree(mpNode) == mNode) { // 대체할 노드의 왼쪽서브트리가 존재
			ChangeLeftSubTree(mpNode, GetRightSubTree(mNode)); // 오른쪽 서브트리를 왼쪽으로 붙힌다.
		}
		else { // 대체할 노드의 오른쪽 서브트리가 존재하면
			ChangeRightSubTree(mpNode, GetRightSubTree(mNode)); // 대체노드의 오른쪽 서브트리를 붙힌다.
		}

		dNode = mNode;
		SetData(dNode, delData); // 백업 데이터 복원 
	}

	if (GetRightSubTree(Vroot) != (*root)) { 
		// 삭제 과정중 루트가 삭제되어 루트가 바뀌엇을 경우
		(*root) = GetRightSubTree(Vroot);
	}

	free(Vroot);
	return dNode;
}

void ShowBSTData(BSTData data) {
	printf("%d ", data);
}

void BSTShowAll(BTreeNode *bst) {
	InorderTraverse(bst, ShowBSTData);// 중위순회만 오름차순 출력
	//PostorderTraverse(bst, ShowBSTData);
	//PreorderTraverse(bst, ShowBSTData);
}