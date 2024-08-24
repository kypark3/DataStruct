#include <stdio.h>
#include <stdlib.h>

#define BUCKET_NUM 10 // 10자리 정수

typedef int Data;
typedef struct _node {
	Data data;
	struct _node *next;
}Node;

typedef struct _listBaseQueue {
	Node *front;
	Node *rear;
}ListBaseQueue;

typedef ListBaseQueue Queue;

void QueueInit(Queue *q) {
	q->front = NULL;
	q->rear = NULL;
}
int IsEmpty(Queue *q) {
	return q->front == NULL;
}

void Enqueue(Queue *q, Data data) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	if (newNode != NULL) {
		newNode->data = data;
		newNode->next = NULL;
		if (IsEmpty(q)) {
			q->front = newNode;
			q->rear = newNode;
		}
		else {
			q->rear->next = newNode;
			q->rear = newNode;
		}
	}
}

Data Dequeue(Queue *q) {

	if (IsEmpty(q)) {
		printf("Queue is Empty\n");
		exit(-1);
	}
	Node *rNode = q->front;
	Data rData = rNode->data;

	q->front = q->front->next;
	free(rNode);
	return rData;
}

Data QPeek(Queue *q) {
	if (IsEmpty(q)) {
		printf("Queue is Empty\n");
		exit(-1);
	}
	return q->front->data;
}

void RadixSort(int ar[], int arLen, int maxLen) { // sort할 배열, 배열길이, 최대 정수자리수의 갯수
	Queue buckets[BUCKET_NUM];
	int bucketIdx;
	int pos;
	int digitIdx;
	int divdeFactor = 1;
	int radix;

	for (bucketIdx = 0; bucketIdx < BUCKET_NUM; bucketIdx++) {
		QueueInit(&buckets[bucketIdx]);
	}

	for (pos = 0; pos < maxLen; pos++) { //정수의 자리

		for (digitIdx = 0; digitIdx < arLen; digitIdx++) { //배열 길이
			radix = (ar[digitIdx] / divdeFactor) % 10;
			Enqueue(&buckets[radix], ar[digitIdx]); // queue 배열에 정수 집어넣기
		}

		for (bucketIdx = 0, digitIdx = 0; bucketIdx < BUCKET_NUM; bucketIdx++) {

			while (!IsEmpty(&buckets[bucketIdx])) {
				ar[digitIdx++] = Dequeue(&buckets[bucketIdx]);
			}
		}

		divdeFactor *= 10; // 자리수 증가를 위한 곱
	}
}


int main( ) {

	int ar[] = { 13,212,14,7141,10987,6,15 };
	int arLen = sizeof(ar) / sizeof(int);
	RadixSort(ar, arLen, 5);

	for (int i = 0; i < arLen; i++) {
		printf("%d ", ar[i]);
	}

	return 0;
}