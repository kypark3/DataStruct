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
		// ������ ���ص���. showinfo �� ���ϰ� �������Ѱ���.
	}
}

void GraphDestroy(ALGraph *g) {
	int i;

	/*
	// �� ������ ���� ���Ḯ��Ʈ�� ���Ե� ������ ��� ����
	for (i = 0; i < g->numV; i++)
	{
		Node * curNode = g->adjList[i].head->next; // ����Ʈ�� ù ��° ���

		while (curNode != NULL) {
			Node * nextNode = curNode->next; // ���� ��带 �̸� ����
			free(curNode); // ���� ��� ����
			curNode = nextNode; // ���� ���� �̵�
		}
	}
	*/

	// ���� ���� ����Ʈ�� �迭�� ������.
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
		printf("%c�� ����� ���� : ", i + 'A');

		if (LFirst(&(g->adjList[i]), &retval)) {
			printf("%c ", retval + 'A');

			while (LNext(&(g->adjList[i]), &retval)) {
				printf("%c ", retval + 'A');
			}
		}

		printf("\n");
	}
}

