/* Two of the nodes of a Binary Search Tree (BST) are swapped. Fix (or correct) the BST.

Input Tree:
         10
        /  \
       5    8
      / \
     2   20

In the above tree, nodes 20 and 8 must be swapped to fix the tree.  
Following is the output tree
         10
        /  \
       5    20
      / \
     2   8

First Approach:

The inorder traversal of a BST produces a sorted array. So a simple method is to store inorder traversal 
of the input tree in an auxiliary array. Sort the auxiliary array. Finally, insert the auxiilary array 
elements back to the BST, keeping the structure of the BST same. Time complexity of this method is O(nLogn) 
auxiliary space needed is O(n).

Better Approach:

We can solve this in O(n) time and with a single traversal of the given BST. Since inorder traversal of 
BST is always a sorted array, the problem can be reduced to a problem where two elements of a sorted array 
are swapped. There are two cases that we need to handle:

1. The swapped nodes are not adjacent in the inorder traversal of the BST.

 For example, Nodes 5 and 25 are swapped in {3 5 7 8 10 15 20 25}. 
 The inorder traversal of the given tree is 3 25 7 8 10 15 20 5 
If we observe carefully, during inorder traversal, we find node 7 is smaller than the previous visited 
node 25. Here save the context of node 25 (previous node). Again, we find that node 5 is smaller than 
the previous node 20. This time, we save the context of node 5 ( current node ). 
Finally swap the two node’s values.

2. The swapped nodes are adjacent in the inorder traversal of BST.

  For example, Nodes 7 and 8 are swapped in {3 5 7 8 10 15 20 25}. 
  The inorder traversal of the given tree is 3 5 8 7 10 15 20 25 
Unlike case #1, here only one point exists where a node value is smaller than previous node value. 
e.g. node 7 is smaller than node 8.

*/

// Two nodes in the BST's swapped, correct the BST.
#include <stdio.h>
#include <stdlib.h>
 
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
    int data;
    struct node *left, *right;
};
 
// A utility function to swap two integers
void swap( int* a, int* b )
{
    int t = *a;
    *a = *b;
    *b = t;
}
 
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newNode(int data)
{
    struct node* node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}
 
// This function does inorder traversal to find out the two swapped nodes.
// It sets three pointers, first, middle and last.  If the swapped nodes are
// adjacent to each other, then first and middle contain the resultant nodes
// Else, first and last contain the resultant nodes
void correctBSTUtil( struct node* root, struct node** first,
                     struct node** middle, struct node** last,
                     struct node** prev )
{
    if( root )
    {
        // Recur for the left subtree
        correctBSTUtil( root->left, first, middle, last, prev );
 
        // If this node is smaller than the previous node, it's violating
        // the BST rule.
        if (*prev && root->data < (*prev)->data)
        {
            // If this is first violation, mark these two nodes as
            // 'first' and 'middle'
            if ( !*first )
            {
                *first = *prev;
                *middle = root;
            }
 
            // If this is second violation, mark this node as last
            else
                *last = root;
        }
 
        // Mark this node as previous
        *prev = root;
 
        // Recur for the right subtree
        correctBSTUtil( root->right, first, middle, last, prev );
    }
}
 
// A function to fix a given BST where two nodes are swapped.  This
// function uses correctBSTUtil() to find out two nodes and swaps the
// nodes to fix the BST
void correctBST( struct node* root )
{
    // Initialize pointers needed for correctBSTUtil()
    struct node *first, *middle, *last, *prev;
    first = middle = last = prev = NULL;
 
    // Set the poiters to find out two nodes
    correctBSTUtil( root, &first, &middle, &last, &prev );
 
    // Fix (or correct) the tree
    if( first && last )
        swap( &(first->data), &(last->data) );
    else if( first && middle ) // Adjacent nodes swapped
        swap( &(first->data), &(middle->data) );
 
    // else nodes have not been swapped, passed tree is really BST.
}
 
/* A utility function to print Inoder traversal */
void printInorder(struct node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}
 
/* Driver program to test above functions*/
int main()
{
    /*   6
        /  \
       10    2
      / \   / \
     1   3 7  12
     10 and 2 are swapped
    */
 
    struct node *root = newNode(6);
    root->left        = newNode(10);
    root->right       = newNode(2);
    root->left->left  = newNode(1);
    root->left->right = newNode(3);
    root->right->right = newNode(12);
    root->right->left = newNode(7);
 
    printf("Inorder Traversal of the original tree \n");
    printInorder(root);
 
    correctBST(root);
 
    printf("\nInorder Traversal of the fixed tree \n");
    printInorder(root);
 
    return 0;
}