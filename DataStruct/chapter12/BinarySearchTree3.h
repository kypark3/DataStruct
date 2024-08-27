#ifndef __BINARYSEARCHTREE3_H__
#define __BINARYSEARCHTREE3_H__
#include "BinaryTree3.h"

typedef BTData BSTData;

void BSTMakeAndInit(BTreeNode **root);

BSTData BSTGetNodeData(BTreeNode *bst);

BTreeNode* BSTInsert(BTreeNode **root, BSTData data);

BTreeNode* BSTSearch(BTreeNode *bst, BSTData target);

BTreeNode* BSTRemove(BTreeNode **root, BSTData target);

void ShowBSTData(BSTData data);

void BSTShowAll(BTreeNode *bst);

#endif // !__BINARYSEARCHTREE3_H__
