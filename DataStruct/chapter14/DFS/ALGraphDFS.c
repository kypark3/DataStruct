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

// ����� �޸𸮸� �������� ���� ������ ����.
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
		printf("%c�� ����� ���� :", i + 'A');

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

	//ù �湮
	VisitVertex(pg, visitV);
	SPush(&stack, visitV);
	
	//��� �������� ù��° ��θ� Ȯ����
	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE) { 

		int visitFlag = FALSE;
		
		// ���� �������� �湮�� �����ϴٸ�
		if (VisitVertex(pg, nextV) == TRUE) {
			// ���� ��带 �湮�Ҽ� �ֵ��� stack�� push
			SPush(&stack, visitV); 
			visitV = nextV;
			visitFlag = TRUE;
		}
		else // �湮�� �Ұ����ϸ�
		{
			//�������� �ٸ� ��θ� Ȯ����.
			while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE) {

				if (VisitVertex(pg, nextV) == TRUE) {
					SPush(&stack, visitV);
					visitV = nextV;
					visitFlag = TRUE;
					break;
				}
			}
		}

		// �������� ��ε� �߿� �湮�� ���Ͽ�����
		if (visitFlag == FALSE) { 

			// ó�� ���������� ���ƿ�
			if (SIsEmpty(&stack) == TRUE) {
				break; 
			}
			// �湮�ϰ� ������ ������� ������ ���� ����������
			else {
				visitV = SPop(&stack); 
			}

		}
	}

	//���� �湮������ �湮 ���� �ʱ�ȭ
	memset(pg->visitInfo, 0, sizeof(int)*pg->numV); 
}