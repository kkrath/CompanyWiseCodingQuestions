#include<iostream>
#include<vector>
#include<map>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data):data(data), left(nullptr), right(nullptr){}\
    TreeNode(int data, TreeNode* left, TreeNode* right):data(data), left(left), right(right){}
};

void getVerticalorderOfTree(TreeNode* &node, int level, map<int,vector<int>> &result);

void getVerticalorderOfTree(TreeNode* &root){
    map<int,vector<int>> result;
    int level = 0;
    getVerticalorderOfTree(root, level, result);
    map<int, vector<int>>::iterator it;
    for(it = result.begin(); it != result.end(); it++){
        vector<int> nodes = it->second;
        for(auto node : nodes){
            cout << node << ",";
        }
        cout << endl;
    }
}
void getVerticalorderOfTree(TreeNode* &node, int level, map<int, vector<int>> &result){
    if(node == nullptr)
        return;
    result[level].push_back(node->data);
    getVerticalorderOfTree(node->left, level - 1, result);
    getVerticalorderOfTree(node->right, level + 1, result);
    return;
}
int main(){
    TreeNode* root;
    root = new TreeNode(1);
    root->left = new TreeNode(2, new TreeNode(5), new TreeNode(7));
    root->right = new TreeNode(6, new TreeNode(8), new TreeNode(9));
    getVerticalorderOfTree(root);
}