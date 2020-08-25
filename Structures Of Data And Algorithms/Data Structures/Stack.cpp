#include <iostream>
#include <vector>
using namespace std;

class Stack{ //Implementation with vector
private:
	vector<int> data;
public:
	void push(int number) {
		data.push_back(number);
	}
	void pop() {
		data.pop_back;
	}

	int peek() const {
		if (data.size > 0) {
			return data.back();
		}
		else {
			throw std::underflow_error("Stack is empty");
		}
	}

	bool isEmpty() const {
		return (data.size()==0);
	}
};

