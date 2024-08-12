#include <stdio.h>
#pragma warning(disable:4996);
void Hanoi(int num, char from, char by, char to);

int main( ) {

	int n;
	scanf("%d", &n);
	Hanoi(n, 'A', 'B', 'C');

	return 0;
}

void Hanoi(int num, char from, char by, char to) {

	if (num == 1) {
		printf("���� 1�� %c -> %c�� �̵�\n", from, to);
		return;
	}
	
	Hanoi(num - 1, from, to, by);
	printf("���� %d�� %c -> %c�� �̵�\n", num, from, to);
	Hanoi(num - 1, by, from, to);
}
