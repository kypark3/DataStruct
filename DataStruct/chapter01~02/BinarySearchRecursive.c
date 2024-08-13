#include <stdio.h>
#pragma warning(disable:4996)

int BSearchRecur(int ar[], int first, int last, int target);
void Sort(int ar[], int len);

int main( ) {
	int ar[101];
	int n;
	scanf("%d", &n);
	int len = 0;
	while (n != 0) {
		ar[len++] = n;
		scanf("%d", &n);
	}

	int target;
	scanf("%d", &target);

	Sort(ar, len);

	int idx = BSearchRecur(ar, 0, len - 1, target);
	if (idx == -1) {
		printf("Å½»ö ºÒ°¡ idx = %d" , idx);
	}
	else {
		printf("Å½»ö idx = %d", idx);
	}

}
void Sort(int ar[], int len) {

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

int BSearchRecur(int ar[], int first, int last, int target){

	if (first > last) return -1;

	int mid = (first + last) / 2;
	
	if (ar[mid] == target) {
		return mid;
	}
	else {
		if (ar[mid] < target) {
			BSearchRecur(ar, mid + 1, last, target);
		}
		else {
			BSearchRecur(ar, first, mid - 1, target);
		}
	}
}

// 10 5 4 3 1 9 11 2 0 4
