#include<iostream>
#include "TreeNode.hpp"
using namespace std;

bool isValidBST(TreeNode* node, int max, int min){
    /* a tree is a valid binary Search Tree if all the elements in the left
       subtree are smaller than the root and all the elements in the right
       are greater than the root, and the left subtree is a valid BST as well
       as the right BST */

    if(node == nullptr)
        return true;

    if(node->data < min || node->data > max)
        return false;
    return isValidBST(node->left, min, node->data-1)  &&
        isValidBST(node->right, node->data + 1, max);
    
}

int main(){
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(4,new TreeNode(3), new TreeNode(5));
    root->right = new TreeNode(8, new TreeNode(7), new TreeNode(9));
    cout << isValidBST(root, INT32_MIN, INT32_MAX);
}