#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data = 0;
	Node* left = nullptr;
	Node* right = nullptr;
};

class tree {
private:
	int cnt;

public:
	Node* node;
	Node* root;

	tree() {
		root = nullptr;
		node = nullptr;
		cnt = 0;
	}
	
	void insert(int d);
	void inOrder(Node* t);
	void chkCnt();
	void chk(Node* t);
	void del(int d);
	Node* search(Node* node, int d);

};

Node* tree::search(Node* node, int d) {
	if (node == NULL)
		return node;

	if (node->data == d)
		return node;
	else if (node->data < d) 
		search(node->right, d);
	else if (node->data > d) 
		search(node->left, d);

}

void tree::chkCnt() {
	cout << cnt;
	return;
}

void tree::inOrder(Node* node) {
	Node* newNode = new Node();
	if (node == NULL) {
		return;
	}
	else {
		inOrder(node->left);
		cout << node->data << " -> ";
		inOrder(node->right);
	}
}

void tree::chk(Node* node) {
	cout << node->data;
}

void tree::del(int d) {
	Node* newNode = new Node();
	newNode = root;
	while (newNode->data != d) {
		if (newNode->data == d)
			break;
	}

}

void tree::insert(int d) {
	cnt++;
	Node* temp = root;
	Node* newNode = new Node();
	newNode->data = d;
	if (temp == nullptr) {
		root = newNode;
		newNode->data = d;
	}
	else {
		Node* ptr = nullptr;
		while (temp != nullptr) {
			ptr = temp;
			if (d > temp->data) {
				temp = temp->right;
			}
			else {
				temp = temp->left;
			}
		}

		if (ptr->data < d)
			ptr->right = newNode;
		else
			ptr->left = newNode;
	}
}


int main() {
	tree tree;

	tree.insert(53);
	tree.insert(29);
	tree.insert(73);
	tree.chkCnt(); cout << endl;
	tree.insert(10);
	if (tree.search(tree.root, 10) != nullptr) {
		cout << tree.search(tree.root, 10)->data << endl;
	}
	else {
		cout << "¿¡·¯!\n";
	}
	tree.insert(30);
	tree.insert(55);
	tree.insert(79);
	cout << endl;

	tree.inOrder(tree.root);
}