/* Write a program to find the minimum depth of a binary tree

minDepth()
1. If tree is empty then return 0
2. Else
     (a) Get the min depth of left subtree recursively  i.e., 
          call minDepth( tree->left-subtree)
     (a) Get the min depth of right subtree recursively  i.e., 
          call minDepth( tree->right-subtree)
     (c) Get the min of min depths of left and right 
          subtrees and add 1 to it for the current node.
         min_depth = min(min dept of left subtreete, min depth of right subtree) + 1
     (d) Return min_depth

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

int getMinimumDepth(TreeNode* root) {
	if(root == NULL) {
		return 0;
	}
	else {
		if(root->left != NULL && root->right != NULL) {
			return 1 + min(getMinimumDepth(root->left), getMinimumDepth(root->right));
		}
		else if(root->left == NULL) {
			return 1 + getMinimumDepth(root->right);
		}
		else if(root->right == NULL) {
			return 1 + getMinimumDepth(root->left);
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
	
	cout<<getMinimumDepth(root);
}