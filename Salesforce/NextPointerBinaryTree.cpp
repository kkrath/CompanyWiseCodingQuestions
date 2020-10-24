#include<iostream>
using namespace std;

class TreeNode{
    public:
        int data;
        TreeNode* left;
        TreeNode* right;
        TreeNode* parent;
        bool locked = false;
        TreeNode(){}
        TreeNode(int data):data(data), left(nullptr), right(nullptr), parent(nullptr){}
        TreeNode(int data, TreeNode* left, TreeNode* right):data(data), left(left), right(right), parent(nullptr){}
};