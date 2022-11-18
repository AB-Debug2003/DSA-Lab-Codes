#include<iostream>
#include<string>
using namespace std;

class Node{

public:
    int data, key;
    Node* next;
    Node* prev;

    Node()
    {
        key = 0;
        data = 0;
        next = NULL;
        prev = NULL;
    }

    Node(int k, int d)
    {
        key = k;
        data = d;
    }
};

class DoublyLinkedList{

public:
    Node* head;

    DoublyLinkedList()
    {
        head = NULL;
    }

    DoublyLinkedList(Node* n)
    {
        head = n;
    }

    // Check if Node Exists
    Node* nodeExists(int k)
    {
        Node* ptr = head;
        Node* temp = NULL;

        // Traverse Through List
        while (ptr != NULL)
        {
            if (ptr->key == k)
            {
                temp = ptr;
            }
            
            else
            {
                ptr = ptr->next;
            }
        }
    }

    // Append Node Function
    void appendNode(Node* n)
    {
        // Check If Node with same key value already Exists
        if (nodeExists(n->key))
        {
            cout << "Error! Node already Exists with key " << n->key << endl;
        }
        
        else
        {
            // Check If Node is first to be appended
            if (head == NULL)
            {
                head = n;
            }
            
            else
            {
                Node* ptr = head;
                //Traverse to end of List
                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                
                ptr->next = n;
                n->prev = ptr;
                cout << "Node Appended!" << endl;
            }
        }
    }

    // Prepend Node Function
    void prependNode(Node* n)
    {
        if (nodeExists(n->key))
        {
            cout << "Error! Node already Exists with key " << n->key << endl;
        }
        
        else
        {
            if (head == NULL)
            {
                head = n;
                cout << "Node Prepended!" << endl;
            }
            
            else
            {
                head->prev = n;
                n->next = head;
                head = n;
                cout << "Node Prepended!" << endl;
            }
        }
    }

    // Insert Node Function
    void insertNode(Node* n, int k)
    {
        Node* ptr = nodeExists(k);

        if (ptr == NULL)
        {
            cout << "Error! No Node Exists with key " << k << endl;
        }
        
        els
    }
};

int main(){
    
    return 0;
}