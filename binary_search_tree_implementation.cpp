#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};

Node* getNewNode(int data) {
	Node* newNode = new Node;
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

Node* insertIntoBST(Node* root, int data) {
	if(root == NULL) {
		root = getNewNode(data);
	}
	else if(root->data >= data) {
		root->left = insertIntoBST(root->left, data);
	}
	else if(root->data < data) {
		root->right = insertIntoBST(root->right, data);
	}
 	return root;
}

bool searchNodeInBST(Node* root, int data) {
	if(root == NULL) {
		return false;
	}

	if(root->data == data) {
		return true;
	}
	else if(root->data > data) {
		return searchNodeInBST(root->left, data);
	}
	else if(root->data < data) {
		return searchNodeInBST(root->right, data);
	}
}

void printBST(Node* root) {
	if(root == NULL) {
		return;
	}

	printBST(root->left);
	cout<<root->data<<"\n";
	printBST(root->right);
}

int main() {
	Node* root;
	root = NULL;

	root = insertIntoBST(root, 4);
	root = insertIntoBST(root, 3);
	root = insertIntoBST(root, 5);
	root = insertIntoBST(root, 2);
	root = insertIntoBST(root, 7);
	root = insertIntoBST(root, 1);
	root = insertIntoBST(root, 6);

	//printBST(root);

	bool found = searchNodeInBST(root, 5);

	cout<<found;
}