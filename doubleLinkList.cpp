#include<iostream>
#include<string>
using namespace std;

class Node {
public:
    int key;
    int data;
    Node * next;
    Node * previous;

    Node() {
        key = 0;
        data = 0;
        next = NULL;
        previous = NULL;
    }
  
    Node(int k, int d) {
        key = k;
        data = d;
    }
};

class DoublyLinkedList {

    public:
        Node * head;

    DoublyLinkedList() {
        head = NULL;
    }
    DoublyLinkedList(Node * n) {
        head = n;
    }

    Node * nodeExists(int k) {
        Node * temp = NULL;
        Node * ptr = head;

        while (ptr != NULL) {
        if (ptr -> key == k) 
        {
            temp = ptr;
        }
        ptr = ptr -> next;
        }

        return temp;
    }

    // Append a node to the list
    void appendNode(Node * n) {
        if (nodeExists(n -> key) != NULL) 
        {
        cout << "Node Already exists with key value : " << n -> key << ". Append another node with different Key value" << endl;
        } 

        else 
        {
        if (head == NULL) 
        {
            head = n;
            cout << "Node Appended as Head Node" << endl;
        } 

        else 
        {
            Node * ptr = head;
            while (ptr -> next != NULL) {
            ptr = ptr -> next;
            }
            ptr -> next = n;
            n -> previous = ptr;
            cout << "Node Appended" << endl;
        }
        }
    }

    // Prepend Node
    void prependNode(Node * n) {
        if (nodeExists(n -> key) != NULL) {
        cout << "Node Already exists with key value : " << n -> key << ". Append another node with different Key value" << endl;
        } 

        else 
        {
        if (head == NULL) 
        {
            head = n;
            cout << "Node Prepended as Head Node" << endl;
        } 

        else 
        {
            head -> previous = n;
            n -> next = head;
            head = n;
            cout << "Node Prepended" << endl;
        }

        }
    }

    // Insert a Node after a particular node in the list
    void insertNode(int k, Node * n) 
    {
        Node * ptr = nodeExists(k);
        if (ptr == NULL) 
        {
        cout << "No node exists with key value: " << k << endl;
        } 
        else 
        {
        if (nodeExists(n -> key) != NULL) 
        {
            cout << "Node Already exists with key value : " << n -> key << ". Append another node with different Key value" << endl;
        } 
        else 
        {
            Node * nextNode = ptr -> next;
            // inserting at the end
            if (nextNode == NULL) 
            {
            ptr -> next = n;
            n -> previous = ptr;
            cout << "Node Inserted!" << endl;
            }

            else 
            {
            n -> next = nextNode;
            nextNode -> previous = n;
            n -> previous = ptr;
            ptr -> next = n;
            cout << "Node Inserted!" << endl;
            }
        }
        }
    }

    //Delete node Function
    void deleteNode(int k) {
        Node * ptr = nodeExists(k);
        if (ptr == NULL) 
        {
        cout << "No node exists with key value: " << k << endl;
        }

        else 
        {
        if (head -> key == k) 
        {
            head = head -> next;
            cout << "Node UNLINKED with keys value : " << k << endl;
        } 

        else 
        {
            Node * nextNode = ptr -> next;
            Node * prevNode = ptr -> previous;
            // deleting at the end
            if (nextNode == NULL) 
            {
            prevNode -> next = NULL;
            cout << "Node Deleted!" << endl;
            }

            //deleting in between
            else 
            {
            prevNode -> next = nextNode;
            nextNode -> previous = prevNode;
            cout << "Node Deleted!" << endl;
            }
        }
        }
    }
};
int main(){
    DoublyLinkedList d1;
    Node* n1 = new Node;
    d1.appendNode(n1);

    Node* n3 = new Node;
    d1.insertNode(3,n3);

    Node* n2 = new Node;
    d1.prependNode(n2);

    d1.deleteNode(3);
    return 0;
}