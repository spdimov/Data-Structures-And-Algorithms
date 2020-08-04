#include <iostream>
#include <list>
using namespace std;

class Queue {
private:
	list<int> data;
public:
	void push(int number) {
		data.push_back(number);
	}
	void pop() {
		data.pop_front();
	}

	int peek() const {
		if (data.size() > 0) {
			return data.front();
		}
		else {
			throw std::underflow_error("Queue is empty");
		}
	}

	bool isEmpty() const {
		return (data.size() == 0);
	}
};

