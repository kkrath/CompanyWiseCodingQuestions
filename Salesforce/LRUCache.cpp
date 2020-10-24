#include<iostream>
using namespace std;

class Node{
    public:
        int key, value;
        Node *prev, *next;
        Node(int k, int v):key(k),value(v),prev(nullptr),next(nullptr){}
};

