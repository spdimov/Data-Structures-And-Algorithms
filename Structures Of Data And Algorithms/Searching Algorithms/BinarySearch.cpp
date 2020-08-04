#include <iostream>
using namespace std;

bool binarySearch(int* arr, int length, int target) {
	int left = 0;
	int right = length - 1;

	while (left <= right) {
		int mid = (left + right) / 2;

		if (arr[mid] == target) {
			return true;
		}
		if (arr[mid] > target) {
			right = mid - 1;
		}
		if (arr[mid] < target) {
			left = mid + 1;
		}
	}
	return false;
}

bool binarySearchRecursive(int* arr, int left, int right, int target) {
	if (right < left) {
		return false;
	}

	int mid = (right + left) / 2;
	if (arr[mid] == target) {
		return true;
	}
	else if (arr[mid] > target) {
		return binarySearchRecursive(arr, left, mid - 1, target);
	}
	else if (arr[mid < target]) {
		return binarySearchRecursive(arr, mid + 1, right, target);
	}
	return -1;
}