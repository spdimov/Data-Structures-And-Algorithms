#include <iostream>
using namespace std;

#define max(a,b) ((a)>(b)? (a):(b))

struct Node {
	int data;
	int height=0;
	Node* left = nullptr;
	Node* right = nullptr;

	Node() = default;
	Node(int value) {
		data = value;
	}

	void calculateHeight() {
		height = 0;
		if (left) {
			height = max(height, left->height + 1);
		}
		if (right) {
			height = max(height, right->height + 1);
		}
	}

	int leftHeight() const {
		if (left) {
			return left->height + 1;
		}
		return 0;
	}

	int rightHeight() const {
		if (right) {
			return right->height + 1;
		}
		return 0;
	}

	int balance() {
		return leftHeight() - rightHeight();
	}

	void rotateRight() {
		if (!left) {
			return;
		}

		Node* leftRight = this->left->right;
		Node* oldRight = this->right;

		swap(this->data, this->left->data);
		this->right = this->left;
		this->left = this->left->left;
		this->right->left = leftRight;
		this->right->right = oldRight;
	}

	void rotateLeft() {
		if (!right) {
			return;
		}

		Node* rightLeft = this->right->left;
		Node* oldLeft = this->left;

		swap(this->data, this->right->data);
		this->left = this->right;
		this->right = this->right->right;
		this->left->left = oldLeft;
		this->left->right = rightLeft;
	}
	
	void recalculateHeights() {
		if (left) {
			left->calculateHeight();
		}
		if (right) {
			right->calculateHeight();
		}
		this->calculateHeight();
	}

	oid fixTree() {
		if (balance() < -1) { // Right is heavier
			if (right->balance() <= -1) { // RR
				this->rotateLeft();
				recalculateHeights();
			}
			else if (right->balance() >= 1) { // RL
				right->rotateRight();
				this->rotateLeft();
				recalculateHeights();
			}
		}
		else if (balance() > 1) { // Left is heavier
			if (left->balance() >= 1) { // LL
				this->rotateRight();
				recalculateHeights();
			}
			else if (left->balance() <= -1) { // LR
				left->rotateLeft();
				this->rotateRight();
				recalculateHeights();
			}
		}
	}
};

class AVL {
private:
	Node* root = nullptr;

    bool _exists(int value, Node* current) const {
        if (current) {
            if (current->data == value) {
                return true;
            }
            else if (value > current->data) {
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
        else if (value > current->data) {
            current->right = _insert(value, current->right);
        }

        current->calculateHeight();
        current->fixTree();
        return current;
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
            if (!current->left && !current->right) {
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

        current->calculateHeight();
        current->fixTree();

        return current;
    }

public:
    AVL() = default;

    bool exists(int value) const {
        return _exists(value, root);
    }

    void insert(int value) {
        root = _insert(value, root);
    }

    void remove(int value) {
        root = _remove(value, root);
    }

    void inorder() const {
        _inorder(root);
        cout << "\n";
    }

    void preorder() const {
        _preorder(root);
        cout << "\n";
    }

    void postorder() const {
        _postorder(root);
        cout << "\n";
    }
};