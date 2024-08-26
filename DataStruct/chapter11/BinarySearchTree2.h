#ifndef __BINARYSEARCHTREE2_H__
#define __BINARYSEARCHTREE2_H__

#include "BinaryTree3.h"

typedef BTData BSTData;

void BSTMakeAndInit(BTreeNode **root);
BSTData BSTGetNodeData(BTreeNode *bst);
void BSTInsert(BTreeNode **root, BSTData data);
BTreeNode* BSTSearch(BTreeNode *bst, BSTData target);
BTreeNode* BSTRemove(BTreeNode **root, BSTData target);
void BSTShowAll(BTreeNode *bst);

#endif