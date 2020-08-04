#include <iostream>
using namespace std;

int partition(int* arr, int start, int end) {
	int pivot = arr[end];
	int pivotIndex = start;

	for (int i = start;i < end;i++) {
		if (arr[i] < pivot) {
			swap(arr[i], arr[pivotIndex]);
			pivotIndex++;
		}
	}
	swap(arr[end], arr[pivotIndex]);
	return pivotIndex;
}

int kthSmallest(int* arr, int start, int end, int k) {
	if (k > 0 && k <= end - start + 1) {
		int pos = partition(arr, start, end);
		
		if (pos == k) {
			return arr[pos];
		}
		else if (pos > k) {
			return kthSmallest(arr, start, pos - 1, k);
		}
		else if (pos < k) {
			return kthSmallest(arr, pos + 1, end, k);
		}
	}
	return INT_MAX
}