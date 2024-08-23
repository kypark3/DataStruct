#include <stdio.h>
#include <stdlib.h>

void MergeTwoArea(int ar[], int left, int mid, int right) {
	int fidx = left;
	int ridx = mid + 1;

	int *sortAr = (int*)malloc(sizeof(int) * (right + 1));

	int sortIdx = left;
	while (fidx <= mid && ridx <= right) { 
		//앞쪽그룹을 가르키는 인덱스(fidx)가 중간지점을 넘어가거나,  
		//뒤쪽그룹을 가르키는 인덱스(ridx)가 마지막지점을 넘어갈때
		//while문 종료

		if (ar[fidx] <= ar[ridx]) {
			sortAr[sortIdx] = ar[fidx++];
		}
		else {
			sortAr[sortIdx] = ar[ridx++];
		}

		sortIdx++;
	}

	if (fidx > mid) { 
		// 앞쪽그룹이 중간을 넘어서게되면 앞은 이미 정렬이 끝남
		for (int i = ridx; i <= right; i++) {
			sortAr[sortIdx++] = ar[i];
		}
	}
	else {
		// 앞쪽그룹이 중간을 못넘었으면 뒤쪽그룹의 정렬이 이미 끝남.

		for (int i = fidx; i <= mid; i++) {
			sortAr[sortIdx++] = ar[i];
		}
	}

	for (int i = left; i <= right; i++) {
		ar[i] = sortAr[i];
	}

	free(sortAr);
}

void MergeSort(int ar[], int left, int right) {

	if (left < right) {
	
		int mid = (left + right) / 2;
		MergeSort(ar, left, mid);
		MergeSort(ar, mid + 1, right);

		MergeTwoArea(ar, left, mid, right);
	}
}


int main( ) {
	int ar[] = { 2,5,4,9,1,3,6 };
	MergeSort(ar, 0, sizeof(ar) / sizeof(int) - 1);
	
	for (int i = 0; i < sizeof(ar) / sizeof(int); i++) {
		printf("%d ", ar[i]);
	}
	return 0;
}