#include "ALGraphBFS.h"
#include "DLinkedList.h"
#include "CircularQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int whoIsPreced(LData d1, LData d2) {
	if (d1 < d2) return 0;
	else return 1;
}

void GraphInit(ALGraph *pg, int nv) {

	pg->adjList = (List*)malloc(sizeof(List) * nv);
	pg->numE = 0;
	pg->numV = nv;

	for (int i = 0; i < nv; i++) {
		ListInit(&(pg->adjList[i]));
		SetSortRule(&(pg->adjList[i]), whoIsPreced);
	}

	pg->visitInfo = (int*)malloc(sizeof(int) * nv);
	memset(pg->visitInfo, 0, sizeof(int) * nv);
}

void GraphDestroy(ALGraph *pg) {
	if (pg->adjList != NULL && pg->visitInfo != NULL) {
		free(pg->adjList);
		free(pg->visitInfo);
	}
}

void AddEdge(ALGraph *pg, int fromV, int toV) {
	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);
	pg->numE++;
}

void ShowGraphEdgeInfo(ALGraph *pg) {

	LData nextData;
	for (int i = 0; i < pg->numV; i++) {

		printf("%c와 연결된 정점 : ", i + 'A');

		if (LFirst(&(pg->adjList[i]), &nextData)) {
			printf("%c ", nextData + 'A');
		
			while (LNext(&(pg->adjList[i]), &nextData)) {
				printf("%c ", nextData + 'A');
			}
		
		}

		printf("\n");
	}
	printf("\n");
}

int VisitVertex(ALGraph *pg, int visitV) {

	if (pg->visitInfo[visitV] == 0) {
		pg->visitInfo[visitV] = 1;
		printf("%c ", visitV + 'A');
		return TRUE;
	}

	return FALSE;
}

void BFShowGraphVertex(ALGraph *pg, int startV) {
	Queue queue;
	int visitV = startV;
	int nextV;

	QueueInit(&queue);
	VisitVertex(pg, visitV);

	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE) {

		if (VisitVertex(pg,nextV) == TRUE) {
			EnQueue(&queue, nextV);
		}

		while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE) {
			if (VisitVertex(pg, nextV)) {
				EnQueue(&queue, nextV);
			}
		}

		if (QIsEmpty(&queue)) {
			break;
		}
		else {
			visitV = DeQueue(&queue);
		}
	}

	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}