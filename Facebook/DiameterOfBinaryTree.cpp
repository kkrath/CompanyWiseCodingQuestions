#include<iostream>
#include "TreeNode.h"
using namespace std;

int heightOfBinaryTree(TreeNode* root){
    if(root == nullptr)
        return 0;
        
    return max(heightOfBinaryTree(root->left), heightOfBinaryTree(root->right)) + 1;
    
}

int diameterofTree(TreeNode* root){
    if(root == nullptr)
        return 0;
    
    int lHeight = heightOfBinaryTree(root->left);
    int rHeight = heightOfBinaryTree(root->right);

    int lDiameter = diameterofTree(root->left);
    int rDiameter = diameterofTree(root->right);

    return max(max(lDiameter, rDiameter),lHeight + rHeight + 1);
}


int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(4, new TreeNode(7), new TreeNode(8));
    root->right = new TreeNode(7, new TreeNode(6), new TreeNode(5));
    cout << "height of tree : " << heightOfBinaryTree(root) << endl;
    cout << "diameter of a tree : " << diameterofTree(root) << endl;
}