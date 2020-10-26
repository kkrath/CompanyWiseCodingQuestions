#include<iostream>
#include<map>
using namespace std;

struct LinkedNode{
    int data;
    LinkedNode* next;
    LinkedNode* random;
    LinkedNode(int data):data(data),next(nullptr),random(nullptr){}
};

LinkedNode* cloneList(LinkedNode* head){
    if(head == nullptr)
        return head;
    map<LinkedNode*, LinkedNode*> clone_map;
    LinkedNode* curr = head;

    while(curr != nullptr){
        clone_map[curr] = new LinkedNode(curr->data);
        curr = curr->next;
    }

    curr = head;
    while(curr != nullptr){
        LinkedNode* new_node = clone_map[curr];
        new_node->next = clone_map[curr->next];
        new_node->random = clone_map[curr->random];
        curr = curr->next;
    }

    return clone_map[head];
}

int main(){
    LinkedNode* head = new LinkedNode(1);
    LinkedNode* next1 = new LinkedNode(7);
    LinkedNode* next2 = new LinkedNode(5);
    LinkedNode* next3 = new LinkedNode(3);
    LinkedNode* next4 = new LinkedNode(6);

    head->next = next1;
    head->random = next2;
    next1->next = next2;
    next1->random = head;
    next2->next = next3;
    next2->random = next4;
    next3->random = next1;
    next3->next = next4;
    next4->random = next3;

    LinkedNode* pointer = head;

    cout << "initialization done !!" << endl;
    while(pointer != nullptr){
        cout << "(" << pointer->data << ","  << pointer->random->data << ")" << "->";
        pointer = pointer->next;
    }
    cout << "NULL" << endl;

    LinkedNode* cloned_list = cloneList(head);
    pointer = cloned_list;
    while(pointer != nullptr){
        cout << "(" << pointer->data << ","  << pointer->random->data << ")" << "->";
        pointer = pointer->next;
    }
    cout << "NULL" << endl;
    
}