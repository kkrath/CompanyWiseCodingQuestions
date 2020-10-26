#include<iostream>
#include<queue>
#include "TreeNode.hpp"

using namespace std;

/* This program will conver the binary tree into a doubly linkedlist such that
   the left pointer will point to the previous node and right pointer will point
   to the next node in in-order manne */
void convert(TreeNode* root, queue<TreeNode*> &que){
    if(root == nullptr)
        return;
    if(root->left)
        convert(root->left, que);
    que.push(root);
    if(root->right)
        convert(root->right, que);
}

TreeNode* convertToList(TreeNode* root){
    queue<TreeNode*> que;
    convert(root, que);
    if(que.size() <  1)
        return nullptr;
    TreeNode *head = que.front();
    TreeNode *next = que.front();
    que.pop();
    while(!que.empty()){
        TreeNode* curr = que.front();que.pop();
        next->right = curr;
        curr->left = next;
        next = curr;
    }

    return head;
}


int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(8, new TreeNode(3), new TreeNode(7));
    root->right = new TreeNode(6, new TreeNode(1), new TreeNode(2));
    TreeNode* head = convertToList(root);
    while(head != nullptr){
        cout << head->data << "->";
        head = head->right;
    }
    cout << endl;
}