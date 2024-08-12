#include <stdio.h>
#pragma warning(disable:4996)

int BSearch(int ar[], int len, int target) {

	int first = 0;
	int last = len - 1;
	int mid;

	while (first<= last) {

		mid = (first + last) / 2;

		if (target == ar[mid]) {
			return mid;
		}
		else {
			if (target < ar[mid]) {
				last = mid - 1;
			}
			else {
				first = mid + 1;
			}
		}
	}

	return -1;
}

void Sort(int ar[], int len) { // ��������
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len - i - 1; j++) {
			if (ar[j] > ar[j + 1]) {
				int tmp = ar[j];
				ar[j] = ar[j + 1];
				ar[j + 1] = tmp;
			}
		}
	}
}

int main( ) {

	int ar[100];
	int n;
	int idx = 0;
	scanf("%d", &n);
	while (n != 0) {
		ar[idx++] = n;
		scanf("%d", &n);
	}

	int target;
	scanf("%d", &target);

	Sort(ar, idx);
	for (int i = 0; i < idx; i++) {
		printf("%d ", ar[i]);
	}
	printf("\n");

	int matchidx = BSearch(ar, idx, target);
	if (matchidx != -1) {
		printf("Ž�� ���� idx = %d", matchidx);
	}
	else {
		printf("Ž�� ���� idx = -1");
	}

	return 0;
}
