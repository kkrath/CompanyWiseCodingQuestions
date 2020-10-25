#include<iostream>
#include "TreeNode.h"
using namespace std;

int heightOfBinaryTree(TreeNode* root){
    if(root == nullptr)
        return 0;
        
    return max(heightOfBinaryTree(root->left), heightOfBinaryTree(root->right)) + 1;
    
}

pair<int,int> diameterofTree(TreeNode* root){
    if(root == nullptr)
        return make_pair(0,0);
    

    pair<int, int> leftheightDiameter = diameterofTree(root->left);
    pair<int, int> rightHeightDiameter = diameterofTree(root->right);

    int diameter = max(max(leftheightDiameter.first, rightHeightDiameter.first),leftheightDiameter.second + rightHeightDiameter.second );
    int height =  max(leftheightDiameter.second,rightHeightDiameter.second) + 1;
    return make_pair(diameter, height);
}


int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(4, new TreeNode(7), new TreeNode(8));
    root->right = new TreeNode(7, new TreeNode(6), new TreeNode(5));
    pair<int, int> result = diameterofTree(root);
    cout << "height of tree : " << result.second << endl;
    cout<< "diameter of tree: " << result.first << endl;
}