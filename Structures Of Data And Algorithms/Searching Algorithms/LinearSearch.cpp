#include <iostream>
using namespace std;

bool linearSearch(int* arr, int length,int searched) {
	for (int i = 0;i < length;i++) {
		if (arr[i] = searched) {
			return true;
		}
	}
	return false;
}