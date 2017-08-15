/* A full binary tree is defined as a binary tree in which all nodes have either zero or two child nodes.

Conversely, there is no node in a full binary tree, which has one child node.

Algorithm:

To check whether a binary tree is a full binary tree we need to test the following cases :-

1) If a binary tree node is NULL then it is a full binary tree.

2) If a binary tree node does have empty left and right sub-trees, then it is a full binary tree
by definition

3) If a binary tree node has left and right sub-trees, then it is a part of a full binary tree by definition. In this case recursively check if the left and right sub-trees are also binary trees themselves.

4) In all other combinations of right and left sub-trees, the binary tree is not a full binary tree.

Time Complexity = O(n)

Space Complexity = O(1)

*/

#include <iostream>
using namespace std;

struct TreeNode {
	int data;
	TreeNode* left;
	TreeNode* right;
};

TreeNode* getNewNode(int data) {
	TreeNode* newNode = new TreeNode;

	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

TreeNode* insertIntoBST(TreeNode* root, int data) {
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

bool isFullBinaryTree(TreeNode* root) {
	if(root == NULL) {
		return true;
	}
	else {
		if(root->left != NULL && root->right != NULL) {
			return (isFullBinaryTree(root->left) && isFullBinaryTree(root->right));
		}
		else if(root->left == NULL && root->right == NULL) {
			return true;
		}
		else {
			return false;
		}
	}
}

int main() {
	TreeNode* root = NULL;

	root = insertIntoBST(root, 4);
	root = insertIntoBST(root, 3);
	root = insertIntoBST(root, 5);
	root = insertIntoBST(root, 2);
	root = insertIntoBST(root, 1);
	
	cout<<isFullBinaryTree(root);
}