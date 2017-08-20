/* Two trees are identical when they have same data and arrangement of data is also same.

To identify if two trees are identical, we need to traverse both trees simultaneously, 
and while traversing we need to compare data and children of the trees.

Algorithm:

sameTree(tree1, tree2)
1. If both trees are empty then return 1.
2. Else If both trees are non -empty
     (a) Check data of the root nodes (tree1->data ==  tree2->data)
     (b) Check left subtrees recursively  i.e., call sameTree( 
          tree1->left_subtree, tree2->left_subtree)
     (c) Check right subtrees recursively  i.e., call sameTree( 
          tree1->right_subtree, tree2->right_subtree)
     (d) If a,b and c are true then return 1.
3  Else return 0 (one is empty and other is not)

*/

#include <iostream>
using namespace std;
 
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* getNewNode(int data) {
    TreeNode* node = new TreeNode;
    node->data  = data;
    node->left  = NULL;
    node->right = NULL;
 
    return node;
}
 
/* Given two trees, return true if they are
 structurally identical */
int identicalTrees(TreeNode* a, TreeNode* b)
{
    if(a == NULL && b == NULL)
        return 1;
 
    if(a != NULL && b != NULL)
    {
        return
        (
            a->data == b->data &&
            identicalTrees(a->left, b->left) &&
            identicalTrees(a->right, b->right)
        );
    }
     
    return 0;
} 
 
int main()
{
    TreeNode* root1 = getNewNode(1);
    TreeNode* root2 = getNewNode(1);
    
    root1->left = getNewNode(2);
    root1->right = getNewNode(3);
    root1->left->left  = getNewNode(4);
    root1->left->right = getNewNode(5); 
 
    root2->left = getNewNode(2);
    root2->right = getNewNode(3);
    root2->left->left = getNewNode(4);
    root2->left->right = getNewNode(5); 
 
    if(identicalTrees(root1, root2)) {
        cout<<"Both trees are identical.";
    }
    else {
        cout<<"Trees are not identical.";
    }
}