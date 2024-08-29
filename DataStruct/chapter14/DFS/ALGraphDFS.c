#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ALGraphDFS.h"
#include "DLinkedList.h"
#include "ArrayBaseStack.h"

int  WhoIsPreced(LData d1, LData d2) {
	return d1 > d2;
}

void GraphInit(ALGraph *pg, int nv) {
	pg->adjList = (List*)malloc(sizeof(List) * nv);
	pg->numV = nv;
	pg->numE = 0;

	for (int i = 0; i < nv; i++) {
		ListInit(&(pg->adjList[i]));
		SetSortRule(&(pg->adjList[i]), WhoIsPreced);
	}

	pg->visitInfo = (int*)malloc(sizeof(int) * nv);
	memset(pg->visitInfo, 0, sizeof(int) * nv);
}

// 노드의 메모리를 해제하지 않음 문제가 있음.
void GraphDestroy(ALGraph *pg) {
	if (pg->adjList != NULL && pg->visitInfo != NULL) {
		free(pg->adjList);
		free(pg->visitInfo);
	}
}

void AddEdge(ALGraph *pg, int fromV, int toV) {
	Linsert(&(pg->adjList[fromV]), toV);
	Linsert(&(pg->adjList[toV]), fromV);
	pg->numE++;
}

void ShowGraphEdgeInfo(ALGraph *pg) {
	int i;
	int vx;

	for (i = 0; i < pg->numV; i++) {
		printf("%c와 연결된 정점 :", i + 'A');

		if (LFirst(&(pg->adjList[i]), &vx)) {
			printf("%c ", vx + 'A');

			while (LNext(&(pg->adjList[i]), &vx)) {
				printf("%c ", vx + 'A');
			}
		}
		printf("\n");
	}

}

int VisitVertex(ALGraph *pg, int visitV) {
	if (pg->visitInfo[visitV] == 0) {
		pg->visitInfo[visitV] = 1;
		printf("%c ", visitV + 'A');
		return TRUE;
	}

	return FALSE;
}

void DFShowGraphVertex(ALGraph *pg, int startV) {
	Stack stack;
	int visitV = startV;
	int nextV;
	StackInit(&stack);

	//첫 방문
	VisitVertex(pg, visitV);
	SPush(&stack, visitV);
	
	//모든 꼭지점의 첫번째 경로를 확인함
	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE) { 

		int visitFlag = FALSE;
		
		// 다음 꼭지점에 방문이 가능하다면
		if (VisitVertex(pg, nextV) == TRUE) {
			// 이전 노드를 방문할수 있도록 stack에 push
			SPush(&stack, visitV); 
			visitV = nextV;
			visitFlag = TRUE;
		}
		else // 방문이 불가능하면
		{
			//꼭지점의 다른 경로를 확인함.
			while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE) {

				if (VisitVertex(pg, nextV) == TRUE) {
					SPush(&stack, visitV);
					visitV = nextV;
					visitFlag = TRUE;
					break;
				}
			}
		}

		// 꼭지점의 경로들 중에 방문을 못하였으면
		if (visitFlag == FALSE) { 

			// 처음 꼭지점으로 돌아옴
			if (SIsEmpty(&stack) == TRUE) {
				break; 
			}
			// 방문하고 스텍이 비어있지 않으면 이전 꼭지점으로
			else {
				visitV = SPop(&stack); 
			}

		}
	}

	//다음 방문을위해 방문 정보 초기화
	memset(pg->visitInfo, 0, sizeof(int)*pg->numV); 
}