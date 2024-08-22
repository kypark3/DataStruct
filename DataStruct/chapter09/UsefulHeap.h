#ifndef __USEFULLHEAP_H__
#define __USEFULLHEAP_H__

#define TRUE 1
#define FALSE 0

#define HEAP_LEN 100

//typedef char HData;
typedef char *HData; // ¹®ÀÚ¿­
typedef int PriorityComp(HData h1, HData h2);
typedef struct _heap {
	PriorityComp *Comp;
	int numOfData;
	HData heapArr[HEAP_LEN];
}Heap;

void HeapInit(Heap *heap, PriorityComp pc);
int HIsEmpty(Heap *heap);

void HInsert(Heap *heap, HData data);
HData HDelete(Heap *heap);

#endif
