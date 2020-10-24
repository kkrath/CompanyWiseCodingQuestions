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
        bool isLocked();
        bool lock(){
            if(!lock(this))
                this->locked = true;
            return this->locked;
        }
        bool unlock();
    private:
        bool lock(TreeNode* node);
        bool parentLock(TreeNode* node);

};

bool TreeNode::isLocked(){
    return this->locked;
}
bool TreeNode::lock(TreeNode* node){
    if(node == nullptr)
        return false;
    bool l_left = lock(node->left);
    bool l_right = lock(node->right);
    bool l_parent = parentLock(node->parent);
    return node->locked || (l_left || l_right || l_parent);
}
bool TreeNode::parentLock(TreeNode* node){
    if(node == nullptr)
        return false;
    return node->locked || parentLock(node->parent);
    
}


int main(){
    TreeNode* root =  new TreeNode(1);
    root->locked = false;
    root->left = new TreeNode(3, new TreeNode(5), new TreeNode(7));
    root->left->parent = root;
    root->left->left->parent =root->left;
    root->left->right->parent =root->left;
    root->left->left->locked = false;
    root->right = new TreeNode(6, new TreeNode(5), new TreeNode(4));
    root->right->parent = root;
    root->right->left->parent =root->right;
    root->right->right->parent =root->right;
    cout << root->left->lock() << endl;
}
