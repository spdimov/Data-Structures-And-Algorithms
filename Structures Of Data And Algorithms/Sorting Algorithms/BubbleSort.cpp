#include <iostream>
using namespace std;
void bubbleSort(int* arr, int length) {
	for (int i = 0;i < length;i++) {
		for (int j = 0;j < length - i - 1;j++) {
			if(arr[j] > arr[j + 1]){
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}
//Time Complexity  O(n^2)
//Space Complexity O(1)
//Adaptive YES
//Stable YES
//Number Of Comparisons O(n^2)
//Number Of Swaps O(n^2)
//Online NO
//In Place YES