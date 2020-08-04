#include <iostream>
using namespace std;

void merge(int* original, int* mergeArr, int start, int mid, int end) {
	int leftIndex = start;
	int rightIndex = mid + 1;
	int sortedIndex = start;

	while (leftIndex <= mid && rightIndex <= end) {
		if (original[leftIndex] <= original[rightIndex]) {
			mergeArr[sortedIndex] = original[leftIndex];
			leftIndex++;
		}
		else {
			mergeArr[sortedIndex] = original[rightIndex];
			rightIndex++;
		}
		sortedIndex++;
	}

	while (leftIndex <= mid) {
		mergeArr[sortedIndex] = original[leftIndex];
		leftIndex++;
		sortedIndex++;
	}

	while (rightIndex <= end) {
		mergeArr[sortedIndex] = original[rightIndex];
		rightIndex++;
		sortedIndex++;
	}
	
	for (int i = start;i <= end;i++) {
		original[i] = mergeArr[i];
	}
}

void mergeSortRecursive(int* original, int* mergeArr, int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		mergeSortRecursive(original, mergeArr, start, mid);
		mergeSortRecursive(original, mergeArr, mid + 1, end);
		merge(original, mergeArr, start, mid, end);
	}
}

void mergeSort(int* arr, int length) {
	int* mergeArray = new int[length];
	mergeSortRecursive(arr, mergeArray, 0, length - 1);
	delete[] mergeArray;
}
//Time Complexity O(n*logn)
//Space Complexity O(n)
//Adaptive NO
//Stable YES
//Number of comparisons O(n*logn)
//External YES
//Prallel YES
//Online NO
//In place NO

