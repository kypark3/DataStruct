#include "HeapSort_UsefulHeap.h"
#include <stdio.h>

int cmp(HData h1, HData h2) {

	return h2 - h1; // 오름차순 maxheap -> 루트에 가장 큰값
	//return h1 - h2; // 내림차순 minheap -> 루트에 가장 작은값
}

void HeapSort(int ar[], int n, PriorityComp pc) {
	Heap heap;
	HeapInit(&heap, pc);
	int i;

	for (i = 0; i < n; i++) {
		HInsert(&heap, ar[i]);
	}

	for (i = 0; i < n; i++) {
		ar[i] = HDelete(&heap);
	}
}

int main( ) {
	int ar[] = { 5,2,3,1,7 };
	
	HeapSort(ar, sizeof(ar) / sizeof(int), cmp);

	for (int i = 0; i < sizeof(ar) / sizeof(int); i++) {
		printf("%d ", ar[i]);
	}

	return 0;
}