#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#include "TreeNode.hpp"
using namespace std;

TreeNode* deserialize_helper(queue<string> &serialized_node);

std::string serialize(TreeNode* node){
    if(node == nullptr)
        return "X,";
    return std::to_string(node->data) + +","+ serialize(node->left) + serialize(node->right);
}

TreeNode* deserialize(std::string serialized_text){
    queue<string> serialized_nodes;
    char str[serialized_text.size()+1];
    strcpy(str,serialized_text.c_str());
    char *token  = strtok(str, ",");
    while(token != nullptr){
        serialized_nodes.push(token);
        token  = strtok(str, ",");
    }
    return deserialize_helper(serialized_nodes);

}

TreeNode* deserialize_helper(queue<string> &serialized_node){
    if(serialized_node.empty())
        return nullptr;

    std::string node = serialized_node.front();
    serialized_node.pop();
    if(node == "X")
        return nullptr;
    TreeNode* root = new TreeNode(stoi(node));
    root->left = deserialize_helper(serialized_node);
    root->right = deserialize_helper(serialized_node);

    return root;
}

void printTree(TreeNode* root){
    if(root == nullptr){
        cout << "X,";
    }
        return;
    cout << root->data << "," ;
    printTree(root->left);
    printTree(root->right);
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3, new TreeNode(6), new TreeNode(9));
    root->right = new TreeNode(5, new TreeNode(7), new TreeNode(3));
    std::string serialized  = serialize(root);
    // root = deserialize(serialized);
    // cout << endl;
}
