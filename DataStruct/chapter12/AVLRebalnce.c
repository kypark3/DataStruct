#include "AVLRebalnce.h"
#include <stdio.h>

BTreeNode* RotateLL(BTreeNode *bst) {
	BTreeNode *pNode;
	BTreeNode *cNode;

	pNode = bst;
	cNode = GetLeftSubTree(bst);

	// c����� ���� ����Ʈ���� p����� ������ ����Ʈ���� ����
	ChangeLeftSubTree(pNode, GetRightSubTree(cNode)); 
	// c����� ������ ����Ʈ���� p���� ����
	ChangeRightSubTree(cNode, pNode);
	
	return cNode;// root
}

BTreeNode* RotateRR(BTreeNode *bst) {
	BTreeNode *pNode;
	BTreeNode *cNode;

	pNode = bst;
	cNode = GetRightSubTree(bst);

	ChangeRightSubTree(pNode, GetLeftSubTree(cNode));
	ChangeLeftSubTree(cNode, pNode);

	return cNode; // root 
}

BTreeNode* RotateRL(BTreeNode *bst){
	
	BTreeNode *pNode;
	BTreeNode *cNode;

	pNode = bst;
	cNode = GetRightSubTree(bst);

	ChangeRightSubTree(pNode, RotateLL(cNode));
	return RotateRR(pNode);
}

BTreeNode* RotateLR(BTreeNode *bst){
	BTreeNode *pNode;
	BTreeNode *cNode;

	pNode = bst;
	cNode = GetLeftSubTree(bst);
	
	ChangeLeftSubTree(pNode, RotateRR(cNode)); // RR�� ���� LL���·� ����.
	return RotateLL(pNode); // balanceing �� c��带 ����
}

int GetHeight(BTreeNode *bst) {

	if (bst == NULL) {
		return 0;
	}

	int leftH = GetHeight(GetLeftSubTree(bst)); // ���� ����Ʈ�� ���� ���
	int rightH = GetHeight(GetRightSubTree(bst)); // ������ ����Ʈ�� ���� ���

	if (leftH > rightH) { // ū���� ���� ��ȯ
		return leftH + 1;
	}
	else {
		return rightH + 1;
	}

}

int GetHeightDiff(BTreeNode *bst) {

	if (bst == NULL) {
		return 0;
	}

	int leftH = GetHeight(GetLeftSubTree(bst));
	int rightH = GetHeight(GetRightSubTree(bst));

	return leftH - rightH; // ���� ����Ʈ�� ���� - ������ ����Ʈ�� ����
}

BTreeNode *Rebalance(BTreeNode **root) {

	int hDiff = GetHeightDiff(*root);

	if (hDiff >= 2){ // ����ΰ�� ������ �� ����. LL or LR
		if (GetHeightDiff(GetLeftSubTree(*root)) > 0) { 
			// ���� ����Ʈ������ 1�̻� = LL
			(*root) = RotateLL(*root);
		}
		else {
			// LR
			(*root) = RotateLR(*root);
		}
	}

	if (hDiff <= -2) { // �����ΰ�� �������� �� ����. RR or RL
		if (GetHeightDiff(GetRightSubTree(*root)) < 0) {
			// RR
			(*root) = RotateRR(*root);
		}
		else {
			//RL
			(*root) = RotateRL(*root);
		}
	}

	// -1 ~ 1 ���̴� ������ �����̹Ƿ� balancing ���ʿ�
	return *root;
}