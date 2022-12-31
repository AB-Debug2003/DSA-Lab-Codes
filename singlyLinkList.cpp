#include<iostream>
#include<string>
using namespace std;

class Node{

public:
    int key;
    int data;
    Node* next;

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

    SinglyLinkedList(Node* n)
    {
        head = n;
    }

    //Check if node exists
    Node* nodeExist(int k)
    {
        Node* temp = NULL;
        Node* ptr = head;
        while (ptr != NULL)
        {
            if (ptr->key == k)
            {
                temp = ptr;
            }
            ptr = ptr->next;
        }
        return temp;
    }

    //Append Node Function
    void appendNode(Node* n)
    {
        if (nodeExist(n->key)!=NULL)
        {
            cout << "Node already exists at Position " << n->key << endl;
            cout << ". Try with a different Position value" << endl;
        }

        else
        {
            if (head == NULL)
            {
                head = n;
                cout << "Node Appended" << endl;
            }

            else
            {
                Node* ptr = head;
                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = n;
                cout << "Node Appended" << endl;
            }
        }
    }

    // Prepend Node Function
    void prependNode(Node* n)
    {
        // Check if node of same key value already exists
        if (nodeExist(n->key)!=NULL)
        {
            cout << "Node already exists at Position " << n->key;
            cout << ". Try with a different Position value." <<endl;
        }

        else
        {
            n->next = head;
            head = n;
            cout << "Node Prepended" << endl;
        }    
    }

    // Insert Node Function
    void insertNode(int k, Node* n)
    {
        Node* ptr = nodeExist(k);
        if (ptr == NULL)
        {
            cout << "No Node exists at position " << k << endl;
        }
        
        else
        {
            n->next = ptr->next;
            ptr->next = n;
        }       
    }

    // Delete Node Function
    void deleteNode(int k)
    {
        if (head == NULL)
        {
            cout << "Linked List already empty. Can't delete" << endl;
        }
        
        else
        {
            if (head->key == k)
            {
                head = head->next;
                cout << "Node Deleted at position " << k << endl;
            }
            
            else
            {
                Node* temp = NULL;
                Node* prevPtr = head;
                Node* currentPtr = head->next;

                while (currentPtr != NULL)
                {
                    if (currentPtr->key == k)
                    {
                        temp = currentPtr;
                        currentPtr = NULL;
                    }

                    else
                    {
                        prevPtr = prevPtr->next;
                        currentPtr = currentPtr->next;
                    }
                }

                if (temp != NULL)
                {
                    prevPtr->next = temp->next;
                    cout << "Node deleted at position " << k << endl;
                }
                
                else
                {
                    cout << "Node Doesn't exist at position " << k << endl;
                }
            }
        } 
    }
};

int main(){
	Node* n1 = new Node;
	SinglyLinkedList s1;
	s1.appendNode(n1);

	Node* n2 = new Node;
	s1.insertNode(3, n2);
	
	Node* n3 = new Node;
	s1.prependNode(n3);

    s1.deleteNode(3);
	return 0;
}