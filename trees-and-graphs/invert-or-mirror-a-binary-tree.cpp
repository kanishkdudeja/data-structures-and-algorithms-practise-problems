/* Write an Efficient Function to Convert a Binary Tree into its Mirror Tree

Mirror of a Tree: Mirror of a Binary Tree T is another Binary Tree M(T) with left and right children of 
all non-leaf nodes interchanged.

Algorithm – Mirror(tree):

(1)  Call Mirror for left-subtree    i.e., Mirror(left-subtree)
(2)  Call Mirror for right-subtree  i.e., Mirror(right-subtree)
(3)  Swap left and right subtrees.
          temp = left-subtree
          left-subtree = right-subtree
          right-subtree = temp

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

void inorderTraversal(TreeNode* root) {
	if(root == NULL) {
		return;
	}

	inorderTraversal(root->left);
	cout<<root->data<<"\n";
	inorderTraversal(root->right);
}

void invertBinaryTree(TreeNode* root) {
	if(root == NULL) {
		return;
	}

	invertBinaryTree(root->left);
	invertBinaryTree(root->right);

	TreeNode* temp = root->left;
	root->left = root->right;
	root->right = temp;
}

int main() {
	TreeNode* root = getNewNode(1);

	root->left = getNewNode(2);
	root->left->left = getNewNode(4);
	root->left->right = getNewNode(5);

	root->right = getNewNode(3);

	cout<<"In-order traversal before inverting tree"<<"\n";
	inorderTraversal(root);

	invertBinaryTree(root);

	cout<<"In-order traversal after inverting tree:"<<"\n";
	inorderTraversal(root);
}