#include<iostream>
using namespace std;

class Node {
public:
    int key;
    int data;
    Node * next;
    Node * previous;

    Node() 
    {
        key = 0;
        data = 0;
        next = NULL;
        previous = NULL;
    }
    
    Node(int k, int d) 
    {
        key = k;
        data = d;
    }
};

class DoublyLinkedList {

public:
    Node * head;
    DoublyLinkedList() 
    {
        head = NULL;
    }
    DoublyLinkedList(Node * n) 
    {
        head = n;
    }

    //Check if node exists using key value
    Node * nodeExists(int k) 
    {
        Node * temp = NULL;
        Node * ptr = head;

        while (ptr != NULL) 
        {
            if (ptr -> key == k) 
            {
                temp = ptr;
            }

            else
            {
                ptr = ptr -> next;
            }
        }

        return temp;
    }

    //Append a node to the list
    void appendNode(Node * n) 
    {
        // check if node with same key value already exists
        if (nodeExists(n -> key) != NULL) 
        {
            cout << "Error! Node Already exists with key value : " << n -> key << ". Append another node with different Key value" << endl;
        } 
        
        else 
        {
            //Check if node is first to be appended
            if (head == NULL) 
            {
                head = n;
                cout << "Node Appended!" << endl;
            } 
            
            else
            {
                Node * ptr = head;

                //traverse to last node
                while (ptr -> next != NULL) 
                {
                    ptr = ptr -> next;
                }
                ptr -> next = n;
                n -> previous = ptr;
                cout << "Node Appended!" << endl;
            }
        }
    }

    // Prepend Node Function
    void prependNode(Node * n) 
    {
        // check if node with same key value already exists
        if (nodeExists(n -> key) != NULL) 
        {
            cout << "Error! Node Already exists with key value : " << n -> key << ". Append another node with different Key value" << endl;
        } 

        else 
        {
            //check if node is first to be appended
            if (head == NULL) 
            {
                head = n;
                cout << "Node Prepended!" << endl;
            } 
            
            else
            {
                head -> previous = n;
                n -> next = head;
                head = n;
                cout << "Node Prepended!" << endl;
            }
        }
    }

    // Insert a Node Function
    void insertNode(int k, Node * n) 
    {
        Node * ptr = nodeExists(k);

        //check if node exists
        if (ptr == NULL) 
        {
            cout << "Error! No node exists with key value: " << k << endl;
        } 
        
        else 
        {
            //check if key of node to be inserted already exists
            if (nodeExists(n -> key) != NULL) 
            {
                cout << "Error! Node Already exists with key value : " << n -> key << ". Append another node with different Key value" << endl;
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

                //inserting in between
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

    // Delete node Function
    void deleteNode(int k) 
    {
        Node * ptr = nodeExists(k);
        if (ptr == NULL) 
        {
            cout << "Error! No node exists with key value: " << k << endl;
        } 
        else 
        {
            // check first node is the first
            if (head -> key == k) 
            {
                head = head -> next;
                cout << "Node Deleted!" << endl;
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

    // Update node
    void updateNode(int k, int d) 
    {
        Node * ptr = nodeExists(k);
        if (ptr != NULL) 
        {
            ptr -> data = d;
            cout << "Node Updated!" << endl;
        } 
        
        else 
        {
            cout << "Error! Node Doesn't exist with key value : " << k << endl;
        }
    }

    // 7th printing
    void printList() 
    {
        if (head == NULL) 
        {
            cout << "Error! Doubly Linked List is Empty" << endl;
        } 
        
        else 
        {
            cout << endl << "Doubly Linked List Values(#prevNode, Key, Data, nextNode): " << endl;
            Node * temp = head;

            while (temp != NULL) 
            {
                cout << "("<< temp->previous << "," << temp -> key << "," << temp -> data << "," << temp->next << ") <--> ";
                temp = temp -> next;
            }
        }
    }

};

int main() {

    DoublyLinkedList obj;
    int option;
    int key1, k1, data1;
    
    cout << "---Doubly Linked List---" << endl;
    do 
    {
        cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
        cout << "1. appendNode()" << endl;
        cout << "2. prependNode()" << endl;
        cout << "3. insertNode()" << endl;
        cout << "4. deleteNode()" << endl;
        cout << "5. updateNode()" << endl;
        cout << "6. print()" << endl;
        cout << "7. Clear Screen" << endl << endl;
        cin >> option;

        //Node n1;
        Node * n1 = new Node();

        switch (option) 
        {
            case 0:
                cout << "Program Exited" << endl;
                break;

            case 1:
                cout << "Append Node Operation \nEnter key & data of the Node to be Appended" << endl;
                cin >> key1;
                cin >> data1;
                n1 -> key = key1;
                n1 -> data = data1;
                obj.appendNode(n1);
                break;

            case 2:
                cout << "Prepend Node Operation \nEnter key & data of the Node to be Prepended" << endl;
                cin >> key1;
                cin >> data1;
                n1 -> key = key1;
                n1 -> data = data1;
                obj.prependNode(n1);
                break;

            case 3:
                cout << "Insert Node After Operation \nEnter key of existing Node after which you want to Insert this New node: " << endl;
                cin >> k1;
                cout << "Enter key & data of the New Node first: " << endl;
                cin >> key1;
                cin >> data1;
                n1 -> key = key1;
                n1 -> data = data1;
                obj.insertNode(k1, n1);
                break;

            case 4:
                cout << "Delete Node By Key Operation - \nEnter key of the Node to be deleted: " << endl;
                cin >> k1;
                obj.deleteNode(k1);
                break;

            case 5:
                cout << "Update Node By Key Operation - \nEnter key & NEW data to be updated" << endl;
                cin >> key1;
                cin >> data1;
                obj.updateNode(key1, data1);
                break;

            case 6:
                obj.printList();
                break;

            case 7:
                system("cls");
                break;

            default:
            cout << "Error! Enter valid Option number " << endl;
        }
        
    } while (option != 0);

    return 0;
}