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
	// ���� ���� �θ��带 �ٸ� ���� �Բ� �Ϲ�ȭ �ϱ� ����.
	BTreeNode *pNode = Vroot;
	BTreeNode *cNode = *root;
	BTreeNode *dNode;

	ChangeRightSubTree(Vroot, *root);

	// ���� ����带 Ž��
	while (cNode != NULL && GetData(cNode) != target){
		pNode = cNode;

		if (target < GetData(cNode)) {
			cNode = GetLeftSubTree(cNode);
		}
		else {
			cNode = GetRightSubTree(cNode);
		}
	}

	if (cNode == NULL) return NULL; // ���� ����� �������� ������� NULL��ȯ

	dNode = cNode; // ��������� dNode�� ����Ŵ.

	//���� ����
	// 1. �ܸ� ����ΰ��
	if (GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL) {

		if (GetLeftSubTree(pNode) == dNode) {
			RemoveLeftSubTree(pNode);
		}
		else {
			RemoveRightSubTree(pNode);
		}

	}
	// 2. ������ ����� �ڽĳ�尡 �Ѱ��� �ִ� ���
	else if (GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL) {

		BTreeNode *dcNode; // ���� ����� �ڽĳ�带 ����Ŵ
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
	// 3. ������ ����� �ڽĳ�尡 �ΰ��� �ִ� ���
	else {
		BTreeNode *mNode = GetRightSubTree(dNode); //��ü ��� (�����Ͱ� �ٲ� ���)
		BTreeNode *mpNode = dNode;
		BTData delData;

		while (GetLeftSubTree(mNode) != NULL) { // ���� ������ ���� �ּҰ��� ã��.
			mNode = mpNode;
			mpNode = GetLeftSubTree(mNode);
		}

		delData = GetData(dNode); // ��ü�� ������ ���
		SetData(dNode, GetData(mNode)); // ������ ��忡 ��ü�� ����� �����͸� ����

		if (GetLeftSubTree(mpNode) == mNode) { // ��ü�� ����� ���ʼ���Ʈ���� ����
			ChangeLeftSubTree(mpNode, GetRightSubTree(mNode)); // ������ ����Ʈ���� �������� ������.
		}
		else { // ��ü�� ����� ������ ����Ʈ���� �����ϸ�
			ChangeRightSubTree(mpNode, GetRightSubTree(mNode)); // ��ü����� ������ ����Ʈ���� ������.
		}

		dNode = mNode;
		SetData(dNode, delData); // ��� ������ ���� 
	}

	if (GetRightSubTree(Vroot) != (*root)) { 
		// ���� ������ ��Ʈ�� �����Ǿ� ��Ʈ�� �ٲ���� ���
		(*root) = GetRightSubTree(Vroot);
	}

	free(Vroot);
	return dNode;
}

void ShowBSTData(BSTData data) {
	printf("%d ", data);
}

void BSTShowAll(BTreeNode *bst) {
	InorderTraverse(bst, ShowBSTData);// ������ȸ�� �������� ���
	//PostorderTraverse(bst, ShowBSTData);
	//PreorderTraverse(bst, ShowBSTData);
}