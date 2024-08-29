#ifndef __ALGRAPH_H__
#define __ALGRAPH_H__

#include "DLinkedList.h"

enum { A,B,C,D,E,F,G,H,I,J};

typedef struct _ual {
	int numV; // vertext num
	int numE; // Edge num
	List *adjList; // Edge info
}ALGraph;

void GraphInit(ALGraph *g, int numV);
void GraphDestroy(ALGraph *g);

void AddEdge(ALGraph *g, int fromV, int toV);
void ShowGraphEdgeInfo(ALGraph *g);

#endif // !__ALGRAPH_H__
