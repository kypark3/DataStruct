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

int Partition(int ar[], int left, int right) { // ar[] , 0 , ����-1
	
	//int pivot = ar[left]; // ���Ƿ� ���� ù��° (n^2)
	int pivotIdx = FoundPivot(ar, left, (left + right) / 2, right); // �ǹ� ����ȭ  (nlog2n)
	int pivot = ar[pivotIdx];
	int low = left + 1;
	int high = right;
	
	Swap(ar, left, pivotIdx);
	printf("pivot : %d \n", pivot);

	while (low <= high) {

		while (pivot > ar[low] && low <= right) { // ��� ����
			low++;
		}

		while (pivot < ar[high] && high >= (left + 1)) { // ��� ����
			high--;
		}

		if (low <= high) {
			Swap(ar, low, high);
		}
	}

	Swap(ar, left, high);
	return high; // ���ϰ��� pivot�� idx��
}

void QuickSort(int ar[], int left, int right) {

	if (left <= right) {
		int mid = Partition(ar, left, right);

		QuickSort(ar, left, mid - 1); // mid �� ���� �����Ǵ� pivot�� �߽����� ���� �׷�
		QuickSort(ar, mid + 1, right); // mid �� ���λ����Ǵ� pivot�� �߽����� ������ �׷�
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

	2 4 1 3 �� 9 �� ���ؼ� �α׷��� �ٽ� Partition �Լ� ����

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
	1 2 4 3 �������� ��������� �ݺ�


	// ����
	�ǹ��� ȣ���� �� ������ �����ϰų� �߰����� �����ϰų� n�� ȣ�������, ���ɿ� �־� ���̰� �ִ�. 
	�ǿ����� ���������� �־��� ��� n�� �׷��� ������ n�� �񱳸��Ѵ�. ( O(n^2) )
	�߰��� ���������� �־��� ��� log2n�� �׷��� ������ n�� �񱳸� �Ѵ�. ( O(n lon 2n) )

	*/