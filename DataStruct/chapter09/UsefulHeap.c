#include "UsefulHeap.h"
#include <stdio.h>


void HeapInit(Heap *heap, PriorityComp pc) {
	heap->Comp = pc;
	heap->numOfData = 0;
}

int HIsEmpty(Heap *heap) {
	return heap->numOfData == 0;
}

int GetParentIDX(int idx) {
	return idx / 2;
}

int GetLChildIDX(int idx) {
	return idx * 2;
}

int GetRChildIDX(int idx) {
	return idx * 2 + 1;
}

int GetHiPriChildIDX(Heap *heap,int idx) {

	if (GetLChildIDX(idx) > heap->numOfData) return 0;
	else if (GetLChildIDX(idx) == heap->numOfData) return GetLChildIDX(idx);
	else {

		if (heap->Comp(heap->heapArr[GetLChildIDX(idx)],
			heap->heapArr[GetRChildIDX(idx)]) < 0) {
			return GetRChildIDX(idx);
		}
		else {
			return GetLChildIDX(idx);
		}
	}
}

void HInsert(Heap *heap, HData data) {
	int idx = heap->numOfData + 1;

	while (idx != 1) {
		if (heap->Comp(data, heap->heapArr[GetParentIDX(idx)]) > 0) {
			heap->heapArr[idx] = heap->heapArr[GetParentIDX(idx)];
			idx = GetParentIDX(idx);
		}
		else {
			break;
		}
	}

	heap->heapArr[idx] = data;
	heap->numOfData++;
}

HData HDelete(Heap *heap) {

	HData retData = heap->heapArr[1];
	HData lastElem = heap->heapArr[heap->numOfData];

	int parentIdx = 1;
	int childIdx;

	while (childIdx = GetHiPriChildIDX(heap,parentIdx) ) {
		if (heap->Comp(lastElem, heap->heapArr[childIdx]) >= 0) {
			break;
		}

		heap->heapArr[parentIdx] = heap->heapArr[childIdx];
		parentIdx = childIdx;
	}

	heap->heapArr[parentIdx] = lastElem;
	heap->numOfData--;
	return retData;
}

