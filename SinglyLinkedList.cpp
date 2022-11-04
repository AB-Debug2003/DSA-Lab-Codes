#include<iostream>
#include<string>
using namespace std;

class Node{
    int key;
    int data;
    Node* next;

public:
    Node()
    {
        key = 0;
        data = 0;
        next = NULL;
    }

    Node(int key, int data)
    {
        this->key = key;
        this->data = data;
    }
};

class SinglyLinkedList{
    Node* head;

public:
    SinglyLinkedList()
    {
        head = NULL;
    }

    SinglyLinkedList(Node *n)
    {
        head = n;
    }

    Node* nodeExist(int k)
    {
        
    }
};

int main(){
    
    return 0;
}