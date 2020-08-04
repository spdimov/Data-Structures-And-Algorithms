#include<iostream>
using namespace std;
void selectionSort(int* arr, int length) {
	for (int currentIndex = 0;currentIndex < length;currentIndex++) {
		int smallestNumberIndex = currentIndex;
		for (int potentialSmallerNumberIndex = currentIndex + 1;potentialSmallerNumberIndex < length;potentialSmallerNumberIndex++) {
			if (arr[potentialSmallerNumberIndex] < arr[smallestNumberIndex]) {
				smallestNumberIndex = potentialSmallerNumberIndex;
			}
		}
		swap(arr[currentIndex], arr[smallestNumberIndex]);
	}
}
//Time Complexity O(n^2)
//Space Complexity O(1)
//Adaptive NO
//Stable NO
//Number of comparisons O(n^2)
//Number of swaps O(n)
//Online NO
//In Place YES