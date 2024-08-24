#include <stdio.h>

int InterpolationSearch(int ar[], int first, int last, int target) {

	int mid;

	/*
	����Ž���� ���� ����
	if (first > last) {
		return -1; //Ž�� ����
	}
	*/

	if (target < ar[first] || ar[last] < target) { 
		// target�� Ž�� ������ �Ѿ���� ����ؾ���
		return -1;
	}

	/*
	*  ���� : ó���� ã�����ϴ°�(s)�� �ε����� ���� 
			 ó���� ������ �ε����� ���� ����Ѵٶ�� ����.
	
		���� ����

		ar[targetidx](target) - ar[first] : ar[last] - ar[first] 
		= targetidx(mid) - first : last - first

	*/

	mid = ((double)(target - ar[first]) / (ar[last] - ar[first]) * (last - first))
		+ first;

	if (ar[mid] == target) {
		return mid;
	}
	else if (target < ar[mid]) {
		InterpolationSearch(ar, first, mid - 1, target);
	}
	else {
		InterpolationSearch(ar, mid + 1, last, target);
	}
}

int main( ) {
	int ar[] = { 1,3,5,7,9 };

	int idx;
	idx = InterpolationSearch(ar, 0, sizeof(ar) / sizeof(int) - 1, 2);
	if (idx == -1) {
		printf("Ž�� ����\n");
	}
	else {
		printf("Ÿ�� ���� idx : %d\n", idx);
	}

	idx = InterpolationSearch(ar, 0, sizeof(ar) / sizeof(int) - 1, 10);
	if (idx == -1) {
		printf("Ž�� ����\n");
	}
	else {
		printf("Ÿ�� ���� idx : %d \n", idx);
	}

	return 0;
}