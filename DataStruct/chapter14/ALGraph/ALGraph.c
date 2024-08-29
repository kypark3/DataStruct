#include "ALGraph.h"
#include <stdio.h>
#include <stdlib.h>

int WhoIsPrecede(LData d1, LData d2) {
	if (d1 < d2)return 0;
	else return 1;
}

void GraphInit(ALGraph *g, int numV) {
	g->adjList = (List*)malloc(sizeof(List) * numV);
	g->numV = numV;
	g->numE = 0;

	for (int i = 0; i < numV; i++) {
		ListInit(&(g->adjList[i]));
		SetSortRule(&(g->adjList[i]), WhoIsPrecede); 
		// 정렬을 안해도됨. showinfo 시 편하게 보기위한것임.
	}
}

void GraphDestroy(ALGraph *g) {
	int i;

	/*
	// 각 정점의 단일 연결리스트에 포함된 노드들을 모두 해제
	for (i = 0; i < g->numV; i++)
	{
		Node * curNode = g->adjList[i].head->next; // 리스트의 첫 번째 노드

		while (curNode != NULL) {
			Node * nextNode = curNode->next; // 다음 노드를 미리 저장
			free(curNode); // 현재 노드 해제
			curNode = nextNode; // 다음 노드로 이동
		}
	}
	*/

	// 단일 연결 리스트에 배열만 해제함.
	if (g->adjList != NULL) { 
		free(g->adjList);
	}

}

void AddEdge(ALGraph *g, int fromV, int toV) {

	LInsert(&(g->adjList[fromV]), toV);
	LInsert(&(g->adjList[toV]), fromV);

	g->numE += 1;
}

void ShowGraphEdgeInfo(ALGraph *g) {
	int i;
	LData retval;

	for (i = 0; i < g->numV; i++) {
		printf("%c와 연결된 정점 : ", i + 'A');

		if (LFirst(&(g->adjList[i]), &retval)) {
			printf("%c ", retval + 'A');

			while (LNext(&(g->adjList[i]), &retval)) {
				printf("%c ", retval + 'A');
			}
		}

		printf("\n");
	}
}

