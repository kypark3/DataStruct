#include <stdio.h>

void BubbleSort(int ar[] , int n) {

	for (int i = 0; i < n -1 ; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (ar[j] > ar[j + 1]) { // 오름차순
				int tmp = ar[j];
				ar[j] = ar[j + 1];
				ar[j + 1] = tmp;
			}
		}
	}
}


int main( ) {

	int ar[] = { 5,4,9,2 };
	
	BubbleSort(ar, sizeof(ar) / sizeof(int));
	for (int i = 0; i < sizeof(ar) / sizeof(int); i++) {
		printf("%d ", ar[i]);
	}

	return 0;
}