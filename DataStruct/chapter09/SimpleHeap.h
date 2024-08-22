#ifndef __SIMPLEHEAP_H__
#define __SIMPLEHEAP_H__

#define TRUE 1
#define FALSE 0

#define HEAP_LEN

typedef char HData;
typedef int Priority;

typedef struct _heapElem {
	HData data;
	Priority pr;
}HeapElem;

typedef struct _heap {
	int numOfData;
	HeapElem heapArr[HEAP_LEN];
}Heap;

void HeapInit(Heap *heap);
int HIsEmpty(Heap *heap);

void HInsert(Heap *heap, HData data, Priority pr);
HData HDelete(Heap *heap);

#endif // !__SIMPLEHEAP_H__
