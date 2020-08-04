#include <iostream>
using namespace std;

int partition(int* arr, int startIndex, int endIndex) {
	int pivot = arr[endIndex];
	int pivotIndex = startIndex;

	for (int i = startIndex;i <= endIndex;i++) {
		if (arr[i] < pivot) {
			swap(arr[i], arr[pivotIndex]);
			pivotIndex++;
		}
	}
	swap(arr[endIndex], arr[pivotIndex]);
	return pivotIndex;
}

void _quickSort(int* arr, int startIndex, int endIndex) {
	if (startIndex < endIndex) {
		int pivot = partition(arr, startIndex, endIndex);
		_quickSort(arr, startIndex, pivot - 1);
		_quickSort(arr, pivot + 1, endIndex);
	}
}

void quickSort(int* arr, int length) {
	_quickSort(arr, 0, length - 1);
}

//Time Complexity (worst case) O(n^2)
//Time Complexity (average case) O(n*logn)
//Space Complexity O(logn)
//Adaptive NO
//Anti-Adaptive YES
//Stable NO
//Number of comparisons O(n*logn)
//Parallel YES
//Online NO
//In place YES
//Locality YES
