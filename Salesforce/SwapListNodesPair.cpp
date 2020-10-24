#include<iostream>
using namespace std;

struct LinkedNode{
    int data;
    LinkedNode* next;
    LinkedNode(int data):data(data), next(nullptr){}
};

LinkedNode* swapInPair(LinkedNode* head){
    LinkedNode* curr = head;
    LinkedNode* newhead = curr->next;
    LinkedNode* prev = nullptr;
    LinkedNode* next = nullptr; 

    while(curr != nullptr && curr->next != nullptr){
        next = curr->next;
        if(prev != nullptr)
            prev->next = next;
        curr->next = next->next;
        next->next = curr;
        prev = curr;
        curr = curr->next;
    }
    cout << endl;
    head = newhead;
    return head;

}

int main(){
    LinkedNode* head = new LinkedNode(1);
    head->next = new LinkedNode(3);
    head->next->next = new LinkedNode(6);
    head->next->next->next  = new LinkedNode(9);
    head->next->next->next->next = new LinkedNode(4);
    head->next->next->next->next->next = new LinkedNode(5);

    head = swapInPair(head);
    while(head != nullptr){
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}