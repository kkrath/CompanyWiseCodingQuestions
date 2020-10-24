#include<iostream>
#include<vector>
using namespace std;


struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data):data(data), left(nullptr), right(nullptr){}\
    TreeNode(int data, TreeNode* left, TreeNode* right):data(data), left(left), right(right){}
};
void findRootToLeafSumPath(TreeNode* node, int sum, vector<int> path);
void findRootToLeafSumPath(TreeNode* root, int sum){
    vector<int> path;
    findRootToLeafSumPath(root, sum, path);
}

void findRootToLeafSumPath(TreeNode* node, int sum, vector<int> path){
    if(node == nullptr)
        return;
    if(sum < 0)
        return;
    path.push_back(node->data);
    sum = sum - node->data;
    if(sum == 0){
        if(node->left == nullptr && node->right == nullptr){
            for(auto val : path)
                cout << val << ",";
            cout << endl;
            return;
        }else
            return;
    }
    findRootToLeafSumPath(node->left, sum, path);
    findRootToLeafSumPath(node->right, sum, path);  
}

int main(){
    TreeNode* root;
    root = new TreeNode(1);
    root->left = new TreeNode(3, new TreeNode(5), new TreeNode(7));
    root->right = new TreeNode(6, new TreeNode(5), new TreeNode(4));
    findRootToLeafSumPath(root, 11);
}