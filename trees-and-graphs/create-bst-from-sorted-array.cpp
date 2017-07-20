/* Problem: Create BST from a sorted array */

/* Time Complexity - O(n) where n is the number of nodes in the tree */

#include <iostream>
#include <limits>
#include <queue>
using namespace std;

int imin = std::numeric_limits<int>::min(); // minimum value
int imax = std::numeric_limits<int>::max();

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

Node* createBSTFromSortedArray(Node* root, int* arr, int low, int high) {
	int median = (low + high)/2;

	root = insertIntoBST(root, arr[median]);

	if(low <= median - 1) {
		createBSTFromSortedArray(root, arr, low, median-1);
	}

	if(high >= median + 1) {
		createBSTFromSortedArray(root, arr, median+1, high);
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

void inOrderTraversal(Node* root) {
	if(root == NULL) {
		return;
	}

	inOrderTraversal(root->left);
	cout<<root->data<<"\n";
	inOrderTraversal(root->right);
}

void preOrderTraversal(Node* root) {
	if(root == NULL) {
		return;
	}

	cout<<root->data<<"\n";
	preOrderTraversal(root->left);
	preOrderTraversal(root->right);
}

void postOrderTraversal(Node* root) {
	if(root == NULL) {
		return;
	}

	postOrderTraversal(root->left);
	postOrderTraversal(root->right);
	cout<<root->data<<"\n";
}

void levelOrderTraversal(Node* root) {
	if(root == NULL) {
		return;
	}

	queue<Node*> q;

	q.push(root);

	while(!q.empty()) {
		Node* tmp = q.front();

		cout<<tmp->data<<"\n";

		if(tmp->left != NULL) q.push(tmp->left);
		if(tmp->right != NULL) q.push(tmp->right);

		q.pop();
	}
}

int main() {
	Node* root;
	root = NULL;

	int arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	root = createBSTFromSortedArray(root, arr, 0, 8);

	cout<<"Printing level order traversal:"<<"\n";
	levelOrderTraversal(root);
	
	cout<<"Printing in order traversal:"<<"\n";
	inOrderTraversal(root);

	cout<<"Printing pre order traversal:"<<"\n";
	preOrderTraversal(root);

	cout<<"Printing post order traversal:"<<"\n";
	postOrderTraversal(root);
}