#include <iostream>
using namespace std;

bool ternarySearch(int* arr, int length, int target) {
	int left = 0;
	int right = length - 1;

	while (left <= right) {
		int leftThird = left + (right - left) / 3;
		int rightThird = right - (right - left) / 3;

		if (arr[leftThird] == target) {
			return true;
		}
		if (arr[rightThird] == target) {
			return true;
		}
		if(target<arr[leftThird]){
			right = leftThird - 1;
		}
		else if (target > arr[rightThird]) {
			left = rightThird + 1;
		}
		else {
			left = leftThird + 1;
			right = rightThird - 1;
		}
	}
	return false
}