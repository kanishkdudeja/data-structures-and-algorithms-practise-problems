/* Successor: Write an algorithm to find the "next" node (i.e., in-order successor) of a given node in a
binary search tree. You may assume that each node has a link to its parent. */

#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
	Node* parent;
};

Node* search(Node* root, int data) {
	if(root == NULL) {
		return NULL;
	}

	if(root->data == data) {
		return root;
	}
	else if(root->data > data) {
		return search(root->left, data);
	}
	else if(root->data < data) {
		return search(root->right, data);
	}
}

/* This function continues traversing down the left path and returns the data of the last node.
Therefore, it returns the smallest node in the tree */
int findSmallestNodeInTree(Node* root) {
	if(root == NULL) {
		return -1;
	}

	Node* temp = root;

	while(temp->left != NULL) {
		temp = temp->left;
	}

	return temp->data;
}

int findInorderSuccessor(Node* root, int  data) {
	Node* givenNode = search(root, data);

	//Signifies that the given node was itself not found
	if(givenNode == NULL) {
		return -1;
	}

	//Right subtree of given node is not empty
	if(givenNode->right != NULL) {
		return findSmallestNodeInTree(givenNode->right);
	}
	//Find nearest ancestor for which given node would be in it's left subtree
	else {
		Node* temp = givenNode;
		Node* parent = givenNode->parent;

		while(parent != NULL && parent->left != temp) {
			temp = parent;
			parent = parent->parent;
		}

		return parent->data;
	}
}