#include "UsefulHeap.h"
#include <stdio.h>
#include <string.h>

/*
-- heap을 기반으로 우선순위Queue 구현 --
우선순위 큐는 데이터를 우선순위에 따라 처리하는 개념적인 구조 (ADT)
-> 따라서 힙 말고 다른 자료구조로도 구현할 수 있다는 얘기가됨
-> 힙으로 구현하는 이유는 big o가 log n 이고 구현의 복잡성이 낮기때문

힙은 우선순위큐를 구현하기 위한 특정 자료구조
*/

int cmp(HData h1, HData h2) {
	// h1이 h2보다 작다 -> h1 우선순위가 높다(양수 리턴)
	// h1과 h2가 같다 -> 우선순위 동일(0 리턴)
	// h1이 h2 보다 크다 -> h1 우선순위가 낮다 (음수 리턴)
	
	//return h2 - h1; 

	/*
	Q90 - 1
	문자열 저장 및 그 문자열의 길이가 짧을 수록 우선순위 높음.
	*/

	return strlen(h2) - strlen(h1);
}

int main( ) {

	Heap heap;
	HeapInit(&heap, cmp);

	HInsert(&heap, "abcd");
	HInsert(&heap, "abc");
	HInsert(&heap, "ab");
	HInsert(&heap, "a");
	printf("%s\n", HDelete(&heap));
	/*
	HInsert(&heap, "a");
	HInsert(&heap, "ab");
	HInsert(&heap, "abc");
	printf("%s\n", HDelete(&heap));
	*/
	while (!HIsEmpty(&heap)) {
		printf("%s ", HDelete(&heap));
	}

	return 0;
}