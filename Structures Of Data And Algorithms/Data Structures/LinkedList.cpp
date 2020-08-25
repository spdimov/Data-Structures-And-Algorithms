#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next=nullptr;

	Node(int data, Node* next=nullptr) {
		this->data = data;
		this->next = next;
	}

};

class LinkedList {
private:
	Node* head = nullptr;
	Node* tail = nullptr;

public:

	void deleteLL() {
		Node* current = head;
		while (current) {
			Node* next = current->next;
			delete current;
			current = next;
		}
	}

	~LinkedList() {
		deleteLL();
	}

	void push_front(int number) {
		Node* newNode=new Node(number, head);
		head = newNode;
		if (tail == nullptr) {
			tail = head;
		}
	}

	void push_back(int number) {
		if (head == nullptr) {
			head = new Node(number);
			tail = head;
		}
		else {
			tail->next = new Node(number);
			tail = tail->next;
		}
	}

	int peek_front() {
		if (head != nullptr) {
			return head->data;
		}
		else {
			throw std::out_of_range("List is empty, cannot peek_front()");
		}
	}

	int peek_back() {
		if (tail != nullptr) {
			return tail->data;
		}
		else {
			throw std::out_of_range("List is empty, cannot peek_front()");
		}
	}

	void pop_front() {
		if (head != nullptr) {
			Node* oldHead = head;
			if (tail == head) {
				tail = nullptr;
			}
			head = head->next;
			delete oldHead;
		}
	}

	void pop_back() {
		if (head != nullptr) {
			if (head == tail) {
				delete head;
				head = nullptr;
				tail = nullptr;
			}
			Node* current = head;
			while (current->next != nullptr && current->next != tail) {
				current = current->next;
			}
			delete current->next;
			current->next = nullptr;
			tail = current;
		}
	}

	void insertAtPosition(int number, int position) {
		if (position == 0) {
			push_front(number);
			return;
		}
		if (head == nullptr) {
			throw std::out_of_range("List is empty");
		}
		Node* current = head;
		Node* previous = nullptr;
		for (int i = 0;i < position;i++) {
			previous = current;
			current = current->next;
		}

		previous->next = new Node(number, current);
		if (tail == previous) {
			tail = previous->next;
		}
	}

	int getAtPosition(int position) {
		if (position == 0) {
			return peek_front();
		}

		if (head == nullptr) {
			throw std::out_of_range("List is empty");
		}

		Node* current=head;
		for (int i = 0;i < position;i++) {
			if (current->next != nullptr) {
				current = current->next;
			}
			else {
				throw std::out_of_range("No such position");
			}
		}
		return current->data;

	}

	void removeAtPosition(int position) {
		if (position == 0) {
			pop_back();
			return;
		}

		if (head == nullptr) {
			throw std::out_of_range("List is empty");
		}
		Node* current = head;
		Node* previous = nullptr;
		for (int i = 0;i < position;i++) {
			if (current->next != nullptr) {
				previous = current;
				current = current->next;
			}
			else {
				throw std::out_of_range("No such position");
			}
		}
		previous->next = current->next;
		if (tail == current) {
			tail = previous;
		}
		delete current;
	}
};