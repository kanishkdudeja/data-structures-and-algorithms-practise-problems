/* Write a program to find the maximum depth (height) of a binary tree

maxDepth()
1. If tree is empty then return 0
2. Else
     (a) Get the max depth of left subtree recursively  i.e., 
          call maxDepth( tree->left-subtree)
     (a) Get the max depth of right subtree recursively  i.e., 
          call maxDepth( tree->right-subtree)
     (c) Get the max of max depths of left and right 
          subtrees and add 1 to it for the current node.
         max_depth = max(max dept of left subtree,  
                             max depth of right subtree) 
                             + 1
     (d) Return max_depth

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

int getMaximumDepth(TreeNode* root) {
	if(root == NULL) {
		return 0;
	}
	else {
		if(root->left != NULL && root->right != NULL) {
			return 1 + max(getMaximumDepth(root->left), getMaximumDepth(root->right));
		}
		else if(root->left == NULL) {
			return 1 + getMaximumDepth(root->right);
		}
		else if(root->right == NULL) {
			return 1 + getMaximumDepth(root->left);
		}
	}
}

int main() {
	TreeNode* root = NULL;

	root = insertIntoBST(root, 4);
	root = insertIntoBST(root, 3);
	root = insertIntoBST(root, 5);
	root = insertIntoBST(root, 2);
	root = insertIntoBST(root, 7);
	root = insertIntoBST(root, 1);
	root = insertIntoBST(root, 6);

	cout<<getMaximumDepth(root);
}