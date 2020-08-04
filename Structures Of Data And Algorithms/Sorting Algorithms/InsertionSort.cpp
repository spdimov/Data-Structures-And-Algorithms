#include <iostream>
using namespace std;
void insertionSort(int* arr, int length) {
	for (int nextItemToSortIndex = 1;nextItemToSortIndex < length;nextItemToSortIndex++) {
		for (int potentiallyBiggerItemIndex = nextItemToSortIndex;potentiallyBiggerItemIndex > 0 && arr[potentiallyBiggerItemIndex] < arr[potentiallyBiggerItemIndex - 1];potentiallyBiggerItemIndex--) {
			swap(arr[potentiallyBiggerItemIndex], arr[potentiallyBiggerItemIndex - 1]);
		}
	}
}
//Time Complexity O(n^2)
//Space Complexity O(1)
//Adaptive YES
//Stable YES
//Number of comparisons O(n^2)
//Number of swaps O(n^2)
//Online YES
//In place YES