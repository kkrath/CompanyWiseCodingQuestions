#include<iostream>
#include "TreeNode.h"
using namespace std;


/* This program will merge two sorted linked list */

LinkedNode* mergeSortedLists(LinkedNode* node1, LinkedNode* node2){

    if(node1 == nullptr)
        return node2;
    if(node2 == nullptr)
        return node1;
    LinkedNode* result = nullptr;

    if(node1->data >= node2->data){
        result = node2;
        result->next = mergeSortedLists(node1, node2->next);
    }else{
        result = node1;
        result->next = mergeSortedLists(node1->next, node2);
    }

    return result;      
}


int main(){
    LinkedList ls, lr;
    ls.add(7);
    ls.add(5);
    ls.add(3);
    ls.add(2);

    lr.add(9);
    lr.add(5);
    lr.add(2);
    lr.add(1);

    LinkedNode* result = mergeSortedLists(ls.getHead(), lr.getHead());
    while(result != nullptr){
        cout << result->data << "->";
        result = result->next;
    }
}