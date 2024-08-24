#include <stdio.h>

void Swap(int ar[], int idx1, int idx2) {
	int temp = ar[idx1];
	ar[idx1] = ar[idx2];
	ar[idx2] = temp;
}

int FoundPivot(int ar[], int left, int mid, int right) {
	int samples[3] = { left, mid,right };
	if (ar[samples[0]] > ar[samples[1]]) {
		Swap(samples, 0, 1);
	}

	if (ar[samples[1]] > ar[samples[2]]) {
		Swap(samples, 1, 2);
	}

	if (ar[samples[0]] > ar[samples[1]]) {
		Swap(samples, 0, 1);
	}

	return samples[1];
}

int Partition(int ar[], int left, int right) { // ar[] , 0 , 길이-1
	
	//int pivot = ar[left]; // 임의로 정함 첫번째 (n^2)
	int pivotIdx = FoundPivot(ar, left, (left + right) / 2, right); // 피벗 최적화  (nlog2n)
	int pivot = ar[pivotIdx];
	int low = left + 1;
	int high = right;
	
	Swap(ar, left, pivotIdx);
	printf("pivot : %d \n", pivot);

	while (low <= high) {

		while (pivot > ar[low] && low <= right) { // 경계 지정
			low++;
		}

		while (pivot < ar[high] && high >= (left + 1)) { // 경계 지정
			high--;
		}

		if (low <= high) {
			Swap(ar, low, high);
		}
	}

	Swap(ar, left, high);
	return high; // 리턴값은 pivot의 idx임
}

void QuickSort(int ar[], int left, int right) {

	if (left <= right) {
		int mid = Partition(ar, left, right);

		QuickSort(ar, left, mid - 1); // mid 즉 새로 생성되는 pivot을 중심으로 왼쪽 그룹
		QuickSort(ar, mid + 1, right); // mid 즉 새로생성되는 pivot을 중심으로 오른쪽 그룹
	}
}

int main( ) {
	int ar[] = { 15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
	QuickSort(ar, 0, sizeof(ar) / sizeof(int) - 1);

	for (int i = 0; i < sizeof(ar) / sizeof(int); i++) {
		printf("%d ", ar[i]);
	}

	return 0;
}


/*
	1.
	p l       hr
	5 4 1 3 2 9

	2.
	p       h lr
	5 4 1 3 2 9

	3.
	p       h lr
	2 4 1 3 5 9

	2 4 1 3 과 9 에 대해서 두그룹을 다시 Partition 함수 실행

	4. 1)
	p l   hr
	2 4 1 3

	5.
	p l h r
	2 4 1 3

	6.
	p h l r
	2 1 4 3

	7.
	h p l
	1 2 4 3 위과정을 재귀적으로 반복


	// 주의
	피벗의 호출은 맨 왼쪽을 선택하거나 중간값을 선택하거나 n번 호출되지만, 성능에 있어 차이가 있다. 
	맨왼쪽을 선택했을시 최악의 경우 n번 그룹을 나누고 n번 비교를한다. ( O(n^2) )
	중간값 선택했을시 최악의 경우 log2n번 그룹을 나누고 n번 비교를 한다. ( O(n lon 2n) )

	*/