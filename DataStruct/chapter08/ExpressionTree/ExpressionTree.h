#ifndef __EXPRESSIONTREE_H__
#define __EXPRESSIONTREE_H__

#include "TreeBinaryTree2.h"

BTreeNode* MakeExpTree(char exp[]);
int EvaluateExpTree(BTreeNode *bt);


void ShowPrefixTypeExp(BTreeNode *bt);
void ShowInfixTypeExp(BTreeNode *bt);
void ShowPostfixTypeExp(BTreeNode *bt);

#endif // !__EXPRESSIONTREE_H__
