#include <stdio.h>

void InsertSort(int ar[], int n) { // 오름차순

	int i, j;
	int insData;

	for (i = 1; i < n; i++) {
		insData = ar[i];

		for (j = i - 1 ; j >= 0; j--) {
			if (ar[j] > insData) { // 앞에있는거가 더크면 뒤로 옮기기
				ar[j + 1] = ar[j];
			}
			else {
				break;
			}
		}

		ar[j + 1] = insData;
	}
}


int main( ) {
	int ar[] = { 3,2,7,1,4 };

	InsertSort(ar, sizeof(ar) / sizeof(int));

	for (int i = 0; i < sizeof(ar) / sizeof(int); i++) {
		printf("%d ", ar[i]);
	}
	return 0;
}