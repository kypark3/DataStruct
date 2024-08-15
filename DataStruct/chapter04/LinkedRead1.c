#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct _node {

	int n;
	struct _node* next;

}Node ;

Node* getNode(int data ) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->n = data;
	newNode->next = NULL;
	return newNode;
}

void push(Node **head, Node **tail, int data) {
	Node *newNode = getNode(data);
	
	if (*head == NULL) {
		*head = newNode;
		(*tail) = newNode;
	}
	else {
		newNode->next = *head;
		*head = newNode;
		//(*tail)->next = newNode;
	}
}

void ShowNodeInfo(Node *head, Node *tail) {

	while (head != tail) {
		printf("%d ", head->n);
		head = head->next;
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

	Node *head = NULL;
	Node *tail = NULL;
	Node *cur = NULL;

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