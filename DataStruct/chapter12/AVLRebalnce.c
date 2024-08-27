#include "AVLRebalnce.h"
#include <stdio.h>

BTreeNode* RotateLL(BTreeNode *bst) {
	BTreeNode *pNode;
	BTreeNode *cNode;

	pNode = bst;
	cNode = GetLeftSubTree(bst);

	// c노드의 왼쪽 서브트리를 p노드의 오른쪽 서브트리로 변경
	ChangeLeftSubTree(pNode, GetRightSubTree(cNode)); 
	// c노드의 오른쪽 서브트리를 p노드로 변경
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
	
	ChangeLeftSubTree(pNode, RotateRR(cNode)); // RR을 통해 LL상태로 만듬.
	return RotateLL(pNode); // balanceing 후 c노드를 리턴
}

int GetHeight(BTreeNode *bst) {

	if (bst == NULL) {
		return 0;
	}

	int leftH = GetHeight(GetLeftSubTree(bst)); // 왼쪽 서브트리 높이 계산
	int rightH = GetHeight(GetRightSubTree(bst)); // 오른쪽 서브트리 높이 계산

	if (leftH > rightH) { // 큰값의 높이 반환
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

	return leftH - rightH; // 왼쪽 서브트리 높이 - 오른쪽 서브트리 높이
}

BTreeNode *Rebalance(BTreeNode **root) {

	int hDiff = GetHeightDiff(*root);

	if (hDiff >= 2){ // 양수인경우 왼쪽이 더 높다. LL or LR
		if (GetHeightDiff(GetLeftSubTree(*root)) > 0) { 
			// 왼쪽 서브트리높이 1이상 = LL
			(*root) = RotateLL(*root);
		}
		else {
			// LR
			(*root) = RotateLR(*root);
		}
	}

	if (hDiff <= -2) { // 음수인경우 오른쪽이 더 높다. RR or RL
		if (GetHeightDiff(GetRightSubTree(*root)) < 0) {
			// RR
			(*root) = RotateRR(*root);
		}
		else {
			//RL
			(*root) = RotateRL(*root);
		}
	}

	// -1 ~ 1 사이는 균형인 상태이므로 balancing 불필요
	return *root;
}