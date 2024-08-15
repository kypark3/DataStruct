#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct _node {

	int n;
	struct _node* next;

}Node;

Node* getNode(int data) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	if (newNode != NULL) {
		newNode->n = data;
		newNode->next = NULL;
		return newNode;
	}
	else {
		printf("memory allocation fail\n");
		exit(1);
	}
}

void push(Node **head, Node **tail, int data) {
	Node *newNode = getNode(data);

	(*tail)->next = newNode;
	(*tail) = newNode;

}

void ShowNodeInfo(Node *head, Node *tail) {
	
	Node *cur = head->next;

	while (cur != tail) {
		printf("%d ", cur->n);
		cur = cur->next;
	}

	printf("%d", tail->n);
}

void freeNode(Node *head, Node *tail) {

	while (head != tail) {
		Node *tmp = head;
		head = head->next;
		free(tmp);
	}
	free(tail);
}

int main( ) {

	Node *head = (Node*)malloc(sizeof(Node));
	if (head != NULL) {
		head->next = NULL;
	}
	else {
		printf("memory allocation fail\n");
		exit(1);
	}
	Node *tail = head;
	//Node *cur = head;

	printf("%p\n", head);
	int n;
	scanf("%d", &n);
	while (n != 0) {
		push(&head, &tail, n);
		scanf("%d", &n);
	}

	ShowNodeInfo(head, tail);
	freeNode(head, tail);
	return 0;
}