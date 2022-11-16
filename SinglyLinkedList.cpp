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
        // Check if node of same key value already exists
        if (nodeExist(n->key)!=NULL)
        {
            cout << "Node already exists at Position " << n->key << endl;
            cout << ". Try with a different Position value" << endl;
        }

        else
        {
            //Check if the node is first to be appended
            if (head == NULL)
            {
                head = n;
                cout << "Node Appended" << endl;
            }

            else
            {
                //Traverse Through Linked List to the end
                Node* ptr = head;
                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                //Create Link between nodes
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
            // Check if it is first node
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

                // Traverse Through List
                while (currentPtr != NULL)
                {
                    // Check if Node Exist at enterd position
                    if (currentPtr->key == k)
                    {
                        temp = currentPtr;
                        currentPtr = NULL;
                    }

                    else
                    {
                        // Move to next Nodes
                        prevPtr = prevPtr->next;
                        currentPtr = currentPtr->next;
                    }
                }

                if (temp != NULL)
                {
                    // Delete the Node
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

    // Update Node Data Function
    void updateNode(int k, int data)
    {
        Node* ptr = nodeExist(k);
        if (ptr != NULL)
        {
            ptr->data = data;
            cout << "Node Updated Successfully" << endl;
        }
        
        else
        {
            cout << "Node Doesn't exist at position " << k << endl; 
        }   
    }

    void printList()
    {
        if (head == NULL)
        {
            cout << "Linked list is empty" << endl;
        }
        
        else
        {
            cout << endl << "Singly Linked List Values : " << endl;
            cout << endl << "Position   Data" << endl;
            Node * temp = head;

            while (temp != NULL) 
            {
            cout << temp -> key << "          " << temp -> data << endl;
            temp = temp -> next;
            }
        }
    }
};

int main(){
    SinglyLinkedList s1;

    int option;
    int key, k1, data;
    cout << "---Singly Linked List---" << endl;
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
            cout << "Program Exited" << endl;
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
        }
    } while (option != 0 );
    return 0;    
}