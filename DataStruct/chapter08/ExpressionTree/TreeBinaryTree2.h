#ifndef __TREEBINARYTREE2_H__
#define __TREEBINARYTREE2_H__

#define TRUE 1
#define FALSE 0

typedef int BTData;

typedef struct _bTreeNode {
	BTData data;
	struct _bTreeNode *right;
	struct _bTreeNode *left;
}BTreeNode;

BTreeNode* MakeBTreeNode( );
BTData GetData(BTreeNode *bt);
void SetData(BTreeNode *bt, BTData data);

BTreeNode* GetLeftSubTree(BTreeNode *bt);
BTreeNode* GetRightSubTree(BTreeNode *bt);

void MakeLeftSubTree(BTreeNode *main, BTreeNode *sub);
void MakeRightSubTree(BTreeNode *main, BTreeNode *sub);

typedef void VisitFuncPtr(BTData data);

void PreorderTraverse(BTreeNode *bt, VisitFuncPtr action);
void InorderTraverse(BTreeNode *bt, VisitFuncPtr action);
void PostorderTraverse(BTreeNode *bt, VisitFuncPtr action);

#endif // !__TREEBINARYTREE2_H__
