#include <stdio.h>

int InterpolationSearch(int ar[], int first, int last, int target) {

	int mid;

	/*
	이진탐색시 종료 조건
	if (first > last) {
		return -1; //탐색 실패
	}
	*/

	if (target < ar[first] || ar[last] < target) { 
		// target이 탐색 범위를 넘어선것을 고려해야함
		return -1;
	}

	/*
	*  가정 : 처음과 찾고자하는값(s)의 인덱스의 차와 
			 처음과 마지막 인덱스의 차는 비례한다라는 가정.
	
		보간 공식

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
		printf("탐색 실패\n");
	}
	else {
		printf("타겟 저장 idx : %d\n", idx);
	}

	idx = InterpolationSearch(ar, 0, sizeof(ar) / sizeof(int) - 1, 10);
	if (idx == -1) {
		printf("탐색 실패\n");
	}
	else {
		printf("타겟 저장 idx : %d \n", idx);
	}

	return 0;
}