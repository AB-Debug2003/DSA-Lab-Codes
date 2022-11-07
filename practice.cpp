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

    Node(int k, int d)
    {
        key = k;
        data = d;
    }
};

class SinglLinkedList{
    Node* head;

public:
    SinglLinkedList()
    {
        head = NULL;
    }

    SinglLinkedList(Node* n)
    {
        head = n;
    }

    Node* nodeExist(int k)
    {
        Node* temp = NULL;
        Node* ptr = head;
        while (ptr->next != NULL)
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
        return temp;
    }

    void appendNode(Node* n)
    {
        if (nodeExist(n->key) != NULL)
        {
            cout << "Error! A node already exists at position " << n->key << endl;
        }
        else
        {
            if (head == NULL)
            {
                head->next = n;
                cout << "Node Appended!" << endl;
            }

            else
            {
                Node* ptr = head;
                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = n;
                cout << "Node Appended!" << endl;
            }
        }      
    }

    void prependNode(Node* n)
    {
        if (nodeExist(n->key) != NULL)
        {
            cout << "Error! A node already exists at position " << n->key << endl;
        }
        
        else
        {
            n->next = head;
            head = n;
            cout << "Node Prepended!" << endl;
        }
    }

    void insertNode(int k, Node* n)
    {
        Node* ptr = nodeExist(k);
        if (ptr == NULL)
        {
            cout << "No node exists at position " << k << endl;
        }
        
        else
        {
            n->next = ptr->next;
            ptr->next = n;
            cout << "Node Inserted!" << endl;
        }  
    }

    void deleteNode(int k)
    {
        if (head == NULL)
        {
            cout << "Error! Linked list is Empty" << endl;
        }
        
        else
        {
            if (head->key == k)
            {
                head = head->next;
                cout << "Node Deleted!" << endl;
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
                    cout << "Node Deleted!" << endl;
                }
                
                else
                {
                    cout << "No node exists at position " << k << endl;
                }
            }
        }     
    }

    void updateNode(int k, int d)
    {
        Node* ptr = nodeExist(k);
        if (ptr != NULL)
        {
            ptr->data = d;
            cout << "Node Updated!" << endl;
        }
        
        else
        {
            cout << "No node exists at position " << k << endl;
        }        
    }

    void printList()
    {
        if (head == NULL)
        {
            cout << "Linked List is Empty" << endl;
        }
        
        else
        {
            cout << endl << "Singly Linked List Values : " << endl;
            cout << endl << "Position   Data" << endl;
            Node* ptr = head;
            while (ptr->next != NULL)
            {
                cout << ptr -> key << "          " << ptr -> data << endl;
                ptr = ptr -> next;
            }            
        }        
    }
};

int main(){
    int option;
    int key, k1, data;

    SinglLinkedList s1;

    do
    {
        cout << "\nWhat operation do you want to perform ?" << endl;
		cout << "1. Append Node()" << endl;
		cout << "2. Prepend Node()" << endl;
		cout << "3. Insert Node()" << endl;
		cout << "4. Delete Node()" << endl;
		cout << "5. Update Node()" << endl;
		cout << "6. Print()" << endl;
		cout << "7. Clear Screen" << endl;
        cout << "0. Exit" << endl;
		cin >> option;

        Node* n1 = new Node();

        switch (option)
        {
            case 0:
                cout << "Program Exited!" << endl;
                break;
            
            case 1:
                cout << "Append Node Function \nEnter a Position of Node to be Appended: " << endl;
                cin >> key;
                cout << "Enter Data of Node to be Appended: " << endl;
                cin >> data;
                n1->key = key;
                n1->data = data;
                s1.appendNode(n1);
                break;

            case 2:
                cout << "Prepend Node Function" << endl;
                cout << "Enter the Position of Node to be Prepended: " << endl;
                cin >> key;
                cout << "Enter Data of Node to be Prepended: " << endl;
                cin >> data;
                n1->key = key;
                n1->data = data;
                s1.prependNode(n1);
                break;

            case 3:
                cout << "Insert Node Function" << endl;
                cout << "Enter the Position of Node after which you want to Insert this Node" << endl;
                cin >> k1;
                cout << "Enter the Position of New Node: " << endl;
                cin >> key;
                cout << "Enter the Data of New Node: " << endl;
                cin >> data;
                n1->key = key;
                n1->data = data;
                s1.insertNode(k1,n1);
                break;
                
            case 4:
                cout << "Delete Node Function \nEnter the Position of Node to be Deleted: " << endl;
                cin >> key;
                s1.deleteNode(key);
                break;

            case 5:
                cout << "Update Node Function \nEnter the Position of Node to be Updated: " << endl;
                cin >> key;
                cout << "Enter Data of New Node: " << endl;
                cin >> data;
                s1.updateNode(key, data);
                break;

            case 6:
                s1.printList();
                break;

            case 7:
                system("cls");
                break;

            default:
                cout << "Enter a valid option!" << endl << endl;
                break;
        }

    } while (option != 0);
    
    return 0;
}