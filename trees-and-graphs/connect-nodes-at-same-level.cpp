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

/* Method 2 (Extend Pre Order Traversal)
This approach works only for Complete Binary Trees. In this method we set nextRight in Pre Order fashion to make sure that the nextRight of parent is set before its children. When we are at node p, we set the nextRight of its left and right children. Since the tree is complete tree, nextRight of p’s left child (p->left->nextRight) will always be p’s right child, and nextRight of p’s right child (p->right->nextRight) will always be left child of p’s nextRight (if p is not the rightmost node at its level). If p is the rightmost node, then nextRight of p’s right child will be NULL.

#include <stdio.h>
#include <stdlib.h>
 
struct node
{
  int data;
  struct node *left;
  struct node *right;
  struct node *nextRight;
};
 
void connectRecur(struct node* p);
 
// Sets the nextRight of root and calls connectRecur() for other nodes
void connect (struct node *p)
{
    // Set the nextRight for root
    p->nextRight = NULL;
 
    // Set the next right for rest of the nodes (other than root)
    connectRecur(p);
}
 
/* Set next right of all descendents of p.
   Assumption:  p is a compete binary tree 
void connectRecur(struct node* p)
{
  // Base case
  if (!p)
    return;
 
  // Set the nextRight pointer for p's left child
  if (p->left)
    p->left->nextRight = p->right;
 
  // Set the nextRight pointer for p's right child
  // p->nextRight will be NULL if p is the right most child at its level
  if (p->right)
    p->right->nextRight = (p->nextRight)? p->nextRight->left: NULL;
 
  // Set nextRight for other nodes in pre order fashion
  connectRecur(p->left);
  connectRecur(p->right);
}
 
/* UTILITY FUNCTIONS */
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. 
struct node* newnode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  node->nextRight = NULL;
 
  return(node);
}
 
/* Driver program to test above functions
int main()
{
 
  /* Constructed binary tree is
            10
          /   \
        8      2
      /
    3
  
  struct node *root = newnode(10);
  root->left        = newnode(8);
  root->right       = newnode(2);
  root->left->left  = newnode(3);
 
  // Populates nextRight pointer in all nodes
  connect(root);
 
  // Let us check the values of nextRight pointers
  printf("Following are populated nextRight pointers in the tree "
          "(-1 is printed if there is no nextRight) \n");
  printf("nextRight of %d is %d \n", root->data,
         root->nextRight? root->nextRight->data: -1);
  printf("nextRight of %d is %d \n", root->left->data,
        root->left->nextRight? root->left->nextRight->data: -1);
  printf("nextRight of %d is %d \n", root->right->data,
        root->right->nextRight? root->right->nextRight->data: -1);
  printf("nextRight of %d is %d \n", root->left->left->data,
        root->left->left->nextRight? root->left->left->nextRight->data: -1);
 
  getchar();
  return 0;
}
Run on IDE
Thanks to Dhanya for suggesting this approach.

Time Complexity: O(n)

Why doesn’t method 2 work for trees which are not Complete Binary Trees?
Let us consider following tree as an example. In Method 2, we set the nextRight pointer in pre order fashion. When we are at node 4, we set the nextRight of its children which are 8 and 9 (the nextRight of 4 is already set as node 5). nextRight of 8 will simply be set as 9, but nextRight of 9 will be set as NULL which is incorrect. We can’t set the correct nextRight, because when we set nextRight of 9, we only have nextRight of node 4 and ancestors of node 4, we don’t have nextRight of nodes in right subtree of root.

            1
          /    \
        2        3
       / \      /  \
      4   5    6    7
     / \           / \  
    8   9        10   11

*/