#include<iostream>
#include<queue>
#include "TreeNode.hpp"
using namespace std;

/* This program will conver the binary tree into a doubly linkedlist such that
   the left pointer will point to the previous node and right pointer will point
   to the next node in in-order manne */

void printLevel(TreeNode* root, int const level, int const currLevel){
    if(root == nullptr)
        return;
    if(currLevel == level){
        cout << root->data << ",";
        return;
    }
    printLevel(root->left, level, currLevel+1);
    printLevel(root->right, level, currLevel+1);
}

int main(){
    /* allocate new memory for root node and all other nodes */
    struct TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2, new TreeNode(5), new TreeNode(7));
    root->right = new TreeNode(4, new TreeNode(1), new TreeNode(6));
    printLevel(root, 0, 0);
    delete root->left;
    delete root->right;
    delete root;
}