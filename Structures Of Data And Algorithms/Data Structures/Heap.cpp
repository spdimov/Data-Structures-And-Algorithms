#include <iostream>
#include <vector>
using namespace std;

class Heap {
private:
	vector<int> data;
	
	int getLeft(int pos) {
		return (pos * 2) + 1;
	}

	int getRight(int pos) {
		return (pos * 2) + 2;
	}

	int getParent(int pos) {
		return (pos - 1) / 2;
	}

	void siftUp(int pos) {
		int parent = getParent(pos);
		while (parent >= 0 && data[pos] > data[parent]) {
			swap(data[pos], data[parent]);
			parent = getParent(parent);
			pos = getParent(pos);
		}
	}

	void siftDown(int pos) {
		bool hasLeft = getLeft(pos) < data.size();
		bool hasRight = getRight(pos) < data.size();
		
		if (hasRight && (data[pos] < data[getLeft(pos)] || data[pos] < data[getRight(pos)])) {
			int swapWith = -1;
			if (data[getLeft(pos)] < data[getRight(pos)]) {
				swapWith = getRight(pos);
			}
			else {
				swapWith = getLeft(pos);
			}

			swap(data[pos], data[swapWith]);
			siftDown(swapWith);
		}
		else if (hasLeft && data[pos] < data[getLeft(pos)]) {
			swap(data[pos], data[getLeft(pos)]);
			siftDown(getLeft(pos));
		}
	}
public:
	bool isEmpty() const {
		return data.size();
	}
	void add(int number) {
		data.push_back(number);\
		if (data.size() != 0) {
			siftUp(data.size()-1);
		}
	}
	int peekTop() {
		return data[0];
	}

	void popTop() {
		if (!isEmpty) {
			return;
		}

		swap(data[0], data[data.size() - 1]);
		data.pop_back;
		siftDown(0);
	}
};