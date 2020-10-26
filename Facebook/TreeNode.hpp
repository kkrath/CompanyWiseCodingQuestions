
/* Bianry Tree Abstarction Model */
struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data):data(data),left(nullptr),right(nullptr){}
    TreeNode(int data, TreeNode* left, TreeNode* right):data(data),left(left),right(right){}
};


/* Singly LinkedList Model */

struct LinkedNode{
    int data;
    LinkedNode* next;
    LinkedNode(int data):data(data),next(nullptr){}
};


class LinkedList{
    private:
        LinkedNode* head;
        int length;
    public:
        LinkedList(){
            head = nullptr;
            length = 0;
        }
        void add(int data){
            if(head == nullptr)
                head = new LinkedNode(data);
            else{
                LinkedNode* temp =  new LinkedNode(data);
                temp->next = head;
                head = temp;
    
            }
            length++;
        }

        int size(){
            return length;
        }

        LinkedNode* getHead(){
            return head;
        }

};