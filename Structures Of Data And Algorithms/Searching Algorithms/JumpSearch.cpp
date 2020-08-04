#include <iostream>
using namespace std;

bool jumpSearch(int* arr, int length, int target) {
	int left = 0;
	int step = sqrt(length);
	int right = step;

	while (right < length && arr[right] <= target) {
		left += step;
		right += step;
		if (right > length - 1) {
			right = length;
		}
	}

	for (int i = left;i < right;i++) {
		if (arr[i] == target) {
			return true;
		}
	}

	return false;
}