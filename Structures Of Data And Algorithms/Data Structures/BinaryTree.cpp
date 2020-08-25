#include <iostream>
#include<queue>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;

	Node() = default;

	Node(int value) {
		data = value;
	}
};

class BinarySearchTree {
private:
	Node* root = nullptr;

	bool _exists(int value, Node* current) const {
		if (current) {
			if (current->data == value) {
				return true;
			}
			else if(current->data<value){
				return _exists(value, current->right);
			}
			else {
				return _exists(value, current->left);
			}
		}
		else {
			return false;
		}
	}

	Node* _insert(int value, Node* current) {
		if (!current) {
			return new Node(value);
		}

		if (value < current->data) {
			current->left = _insert(value, current->left);
		}
		else if(value > current->data){
			current->right = _insert(value, current->right);
		}

		return current;
	}

	Node* _remove(int value, Node* current) {
		if (!current) {
			return nullptr;
		}

		if (value < current->data) {
			current->left = _remove(value, current->left);
		}
		else if (value > current->data) {
			current->right = _remove(value, current->right);
		}
		else {
			if (!current -> left && !current->right) {
				free(current);
				return nullptr;
			}
			else if (!current->left) {
				Node* tempRight = current->right;
				free(current);
				return tempRight;
			}
			else if (!current->right) {
				Node* tempLeft = current->left;
				free(current);
				return tempLeft;
			}
			else {
				Node* swapWith = current->right;
				while (swapWith->left) {
					swapWith = swapWith->left;
				}
				current->data = swapWith->data;
				current->right = _remove(swapWith->data, current->right);
			}
		}
	}

	void _inorder(Node* current) const {
		if (current) {
			_inorder(current->left);
			cout << current->data << " ";
			_inorder(current->right);
		}
	}

	void _preorder(Node* current) const {
		if (current) {
			cout << current->data << " ";
			_preorder(current->left);
			_preorder(current->right);
		}
	}

	void _postorder(Node* current) const {
		if (current) {
			_postorder(current->left);
			_postorder(current->right);
			cout << current->data << " ";
		}
	}

public:
	BinarySearchTree() = default;

	bool exist(int value) {
		return _exists(value, root);
	}

	void _insert(int value) {
		root = _insert(value, root);
	}

	void remove(int value) {
		root = _remove(value, root);
	}

	void inorder() const {
		_inorder(root);
	}

	void preorder() const {
		_preorder(root);
	}

	void postorder() const {
		_postorder(root);
	}

	void levelOrderTraversal() const {
		queue<Node*> que;
		que.push(root);

		while (!que.empty()) {
			Node* current = que.front();
			que.pop();
			if (current) {
				cout << current->data << " ";

				if (current->left) {
					que.push(current->left);
				}
				if (current->right) {
					que.push(current->right);
				}
			}
		}
	}
};