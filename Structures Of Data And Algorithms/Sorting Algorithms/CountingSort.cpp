#include <iostream>
using namespace std;

void countingSort(int* arr, int length) {
	int maxNumber = 0;
	for (int i = 0;i < length;i++) {
		if (arr[i] > maxNumber) {
			maxNumber = arr[i];
		}
	}

	int* countingArr = new int[maxNumber + 1];
	for (int i = 0;i < maxNumber + 1;i++) {
		countingArr[i] = 0;
	}

	for (int i = 0;i < length;i++) {
		countingArr[arr[i]]++;
	}
	
	int sortedIndex = 0;
	for (int i = 0;i < length;i++) {
		while (countingArr[sortedIndex] == 0) {
			sortedIndex++;
		}
		arr[i] = sortedIndex;
		countingArr[sortedIndex]--;
	}
	delete[] countingArr;
}