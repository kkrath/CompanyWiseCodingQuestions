#include<iostream>
#include<vector>
#include "TreeNode.h"
#define MARKER '-1' 
using namespace std;


void serialize(TreeNode* node, vector<int> &serialize_array){
    if(node == nullptr)
        return;
    serialize_array.push_back(node->data);
    serialize(node->left, serialize_array);
    serialize(node->right, serialize_array);
    serialize_array.push_back(MARKER);
}

void deserialize(TreeNode* &root, vector<int> serialize_array){

}
int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3, new TreeNode(6), new TreeNode(9));
    root->right = new TreeNode(5, new TreeNode(7), new TreeNode(3));

}
