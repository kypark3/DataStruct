#include <stdio.h>

void SelSort(int ar[], int n) { // ¿À¸§Â÷¼ø
	int i, j;
	int minIdx;
	int temp;

	for (i = 0; i < n - 1; i++) {
		minIdx = i;

		for (j = i + 1; j < n; j++) { // ÃÖ¼Ú°ª Å½»ö
			if (ar[j] < ar[minIdx]) {
				minIdx = j;
			}
		}

		temp = ar[i];
		ar[i] = ar[minIdx];
		ar[minIdx] = temp;
	}
}

int main( ) {

	int ar[] = { 2,1,7,4,6,3,5,9 };
	SelSort(ar, sizeof(ar) / sizeof(int));

	for (int i = 0; i < sizeof(ar) / sizeof(int); i++) {
		printf("%d ", ar[i]);
	}

	return 0;
}