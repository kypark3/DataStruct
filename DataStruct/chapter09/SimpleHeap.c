#include "SimpleHeap.h"
#include <stdio.h>


void HeapInit(Heap *heap) {
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
	return GetLChildIDX(idx) + 1;
}

int GetHiPriChildIDX(Heap *heap, int idx) {
	if (GetLChildIDX(idx) > heap->numOfData) {
		return 0;
	}
	else if (GetLChildIDX(idx) == heap->numOfData) {
		return GetLChildIDX(idx);
	}
	else {
		if (heap->heapArr[GetLChildIDX(idx)].pr > heap->heapArr[GetRChildIDX(idx)].pr)
		{
			return GetRChildIDX(idx);
		}
		else
		{
			return GetLChildIDX(idx);
		}
	}
}

void HInsert(Heap *heap, HData data, Priority pr) {
	int idx = heap->numOfData + 1;
	HeapElem nelem;
	nelem.pr = pr;
	nelem.data = data;

	while (idx != -1) {

		if (pr < heap->heapArr[GetParentIDX(idx)].pr) {
			heap->heapArr[idx] = heap->heapArr[GetParentIDX(idx)];
			idx = GetParentIDX(idx);
		}
		else {
			break;
		}
	}

	heap->heapArr[idx] = nelem;
	heap->numOfData++;
}

HData HDelete(Heap *heap) {
	HData retData = (heap->heapArr[1]).data;
	HeapElem lastElem = heap->heapArr[heap->numOfData];

	int parentIdx = 1;
	int childIdx;
	while (childIdx = GetHiPriChildIDX(heap, parentIdx))
	{
		if (lastElem.pr <= heap->heapArr[childIdx].pr) {
			break;
		}
		heap->heapArr[parentIdx] = heap->heapArr[childIdx];
		parentIdx = childIdx;
	}

	heap->heapArr[parentIdx] = lastElem;
	heap->numOfData--;
	return retData;
}

