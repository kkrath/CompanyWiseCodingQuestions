
/* Bianry Tree Abstarction Model */
struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data):data(data),left(nullptr),right(nullptr){}
    TreeNode(int data, TreeNode* left, TreeNode* right):data(data),left(left),right(right){}
};
