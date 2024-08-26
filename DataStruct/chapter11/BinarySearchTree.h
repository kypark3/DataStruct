#ifndef __BINARYSEARCHTREE_H__
#define __BINARYSEARCHTREE_H__

#include "BinaryTree2.h"

typedef BTData BSTData;

void BSTMakeAndInit(BTreeNode **root );
BSTData BSTGetNodeData(BTreeNode *bst);
void BSTInsert(BTreeNode **root, BSTData data);
BTreeNode* BSTSearch(BTreeNode *bst, BSTData data);

#endif // !__BINARYSEARCH_H__
