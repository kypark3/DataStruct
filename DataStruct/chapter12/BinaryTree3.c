#include "BinaryTree3.h"

#include <stdio.h>
#include <stdlib.h>

BTreeNode * MakeBTreeNode( ) {
	BTreeNode *newNode = (BTreeNode*)malloc(sizeof(BTreeNode));
	if (newNode != NULL) {
		newNode->left = NULL;
		newNode->right = NULL;
	}
	return newNode;
}

BTData GetData(BTreeNode *bt) {
	return bt->data;
}
void SetData(BTreeNode *bt, BTData data) {
	bt->data = data;
}

BTreeNode* GetLeftSubTree(BTreeNode *bt) {
	return bt->left;
}

BTreeNode* GetRightSubTree(BTreeNode *bt) {
	return bt->right;
}

void MakeLeftSubTree(BTreeNode *main, BTreeNode *sub) {
	
	if (main->left != NULL) { // 최초에 생성시는 필요하지 않지만, 구조변경시 필요
		FreeNode(main->left);
	}
	main->left = sub;
}

void MakeRightSubTree(BTreeNode *main, BTreeNode *sub) {
	if (main->right != NULL) { // 최초에 생성시는 필요하지 않지만, 구조변경시 필요
		FreeNode(main->right);
	}
	main->right = sub;
}

typedef void VisitFuncPtr(BTData data);

void PreorderTraverse(BTreeNode *bt, VisitFuncPtr action) {

	if (bt == NULL) return;
	action(bt->data);
	PreorderTraverse(bt->left, action);
	PreorderTraverse(bt->right,action);
}

void InorderTraverse(BTreeNode *bt, VisitFuncPtr action) {

	if (bt == NULL) return;
	InorderTraverse(bt->left, action);
	action(bt->data);
	InorderTraverse(bt->right, action);

}

void PostorderTraverse(BTreeNode *bt, VisitFuncPtr action) {

	if (bt == NULL) return;

	PostorderTraverse(bt->left, action);
	PostorderTraverse(bt->right, action);
	action(bt->data);
}

BTreeNode* RemoveLeftSubTree(BTreeNode *bt) {
	
	BTreeNode *delNode = NULL;
	if (bt->left != NULL) {
		delNode = bt->left;
		bt->left = NULL;
	}
	return delNode;
}

BTreeNode* RemoveRightSubTree(BTreeNode *bt) {

	BTreeNode *delNode = NULL;
	if (bt->right != NULL) {
		delNode = bt->right;
		bt->right = NULL;
	}
	return delNode;
}

void ChangeLeftSubTree(BTreeNode *main, BTreeNode *sub) {
	main->left = sub;
}
void ChangeRightSubTree(BTreeNode *main, BTreeNode *sub) {
	main->right = sub;
}

void FreeNode(BTreeNode *bt) {

	if (bt == NULL) {
		return;
	}

	FreeNode(bt->left);
	FreeNode(bt->right);
	free(bt);
}