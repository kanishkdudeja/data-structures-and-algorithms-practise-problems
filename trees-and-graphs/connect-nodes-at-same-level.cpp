/* Write a function to connect all the adjacent nodes at the same level in a binary tree.

Example:

Input Tree
       A
      / \
     B   C
    / \   \
   D   E   F


Output Tree
       A--->NULL
      / \
     B-->C-->NULL
    / \   \
   D-->E-->F-->NULL 

In this post, We have discussed Level Order Traversal with NULL markers which are needed to mark levels in tree.

Time Complexity = O(n)

*/

#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
	int data;
	TreeNode* left;
	TreeNode* right;
	TreeNode* nextRight;
};

TreeNode* getNewNode(int data) {
	TreeNode* newNode = new TreeNode;
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->nextRight = NULL;

	return newNode;
}

void connectNodesAtSameLevel(TreeNode* root) {
	queue<TreeNode*> q;

	if(root == NULL) {
		return;
	}

	q.push(root);

	// null marker to represent end of current level
	q.push(NULL);

	// Do Level order of tree using NULL markers
	while(!q.empty()) {
		TreeNode* current = q.front();

		q.pop();

		if(current != NULL) {

			// next element in queue represents next 
            // node at current level
			current->nextRight = q.front();

			// push left and right children of current
            // node
			if(current->left != NULL) {
				q.push(current->left);
			}

			if(current->right != NULL) {
				q.push(current->right);
			}
		}
		// if queue is not empty, push NULL to mark 
        // nodes at this level are visited
		else if(!(q.empty())) {
			q.push(NULL);
		}
	}
}

int main() {
 
    /* Constructed binary tree is
              10
            /   \
          8      2
        /         \
      3            90
    */

    TreeNode* root = getNewNode(10);
    root->left = getNewNode(8);
    root->right = getNewNode(2);
    root->left->left = getNewNode(3);
    root->right->right = getNewNode(90);
 
    // Populates nextRight pointer in all nodes
    connectNodesAtSameLevel(root);
 
    // Let us check the values of nextRight pointers
    printf("Following are populated nextRight pointers in \n"
     "the tree (-1 is printed if there is no nextRight) \n");
    printf("nextRight of %d is %d \n", root->data,
     root->nextRight ? root->nextRight->data : -1);
    printf("nextRight of %d is %d \n", root->left->data,
     root->left->nextRight ? root->left->nextRight->data : -1);
    printf("nextRight of %d is %d \n", root->right->data,
     root->right->nextRight ? root->right->nextRight->data : -1);
    printf("nextRight of %d is %d \n", root->left->left->data,
     root->left->left->nextRight ? root->left->left->nextRight->data : -1);
    printf("nextRight of %d is %d \n", root->right->right->data,
     root->right->right->nextRight ? root->right->right->nextRight->data : -1);
}