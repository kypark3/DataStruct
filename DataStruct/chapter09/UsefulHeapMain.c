#include "UsefulHeap.h"
#include <stdio.h>
#include <string.h>

/*
-- heap�� ������� �켱����Queue ���� --
�켱���� ť�� �����͸� �켱������ ���� ó���ϴ� �������� ���� (ADT)
-> ���� �� ���� �ٸ� �ڷᱸ���ε� ������ �� �ִٴ� ��Ⱑ��
-> ������ �����ϴ� ������ big o�� log n �̰� ������ ���⼺�� ���⶧��

���� �켱����ť�� �����ϱ� ���� Ư�� �ڷᱸ��
*/

int cmp(HData h1, HData h2) {
	// h1�� h2���� �۴� -> h1 �켱������ ����(��� ����)
	// h1�� h2�� ���� -> �켱���� ����(0 ����)
	// h1�� h2 ���� ũ�� -> h1 �켱������ ���� (���� ����)
	
	//return h2 - h1; 

	/*
	Q90 - 1
	���ڿ� ���� �� �� ���ڿ��� ���̰� ª�� ���� �켱���� ����.
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