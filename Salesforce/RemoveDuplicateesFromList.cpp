#include<iostream>
using namespace std;

struct LinkedNode{
    int data;
    LinkedNode* next;
    LinkedNode(int data):data(data), next(nullptr){}
};

void removeDuplicates(LinkedNode* &head){
    LinkedNode* curr = head;
    while(curr != nullptr && curr->next != nullptr){

        while(curr->next != nullptr && curr->data == curr->next->data){
            curr->next = curr->next->next;
        }
        curr = curr->next;
    }

}


int main(){
    LinkedNode* head = new LinkedNode(6);
    head->next = new LinkedNode(6);
    head->next->next = new LinkedNode(6);
    head->next->next->next  = new LinkedNode(9);
    head->next->next->next->next = new LinkedNode(9);
    head->next->next->next->next->next = new LinkedNode(9);

    removeDuplicates(head);
    while(head != nullptr){
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}