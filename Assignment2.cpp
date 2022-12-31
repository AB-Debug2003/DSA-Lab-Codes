#include<iostream>
#include<string>
using namespace std;

class Node{

public:
    int priority;
    string name;
    Node* next;
    Node* prev;

    Node()
    {
        priority = 0;
        name = "";
        next = NULL;
        prev = NULL;
    }

    Node(int priority, string name)
    {
        this->priority = priority;
        this->name = name;
    }
};

class priorityQueue{
public:
    Node* head;
    Node* front;

    priorityQueue()
    {
        head = NULL;
        front == NULL;
    }

    priorityQueue(Node* n)
    {
        head = n;
        front = n;
        
    }

    //Check duplicate priority
    Node* priorityExist(int p)
    {   
        Node* ptr = head;
        Node* temp = NULL;

        while (ptr != NULL)
        {
            if (ptr->priority == p)
            {
                temp = ptr;
            }
            ptr = ptr->prev;
        }
        return temp;
    }

    // Insert value Function
    void Enqueue(Node* n)
    {
        if (priorityExist(n->priority) != NULL && head != NULL)
        {
            cout << "Error! Duplicate priority detected " << endl;
            cout << "Enter a different priority" << endl;
        }
        
        else
        {
            // First value to be inserted
            if (head == NULL)
            {
                head = n;
                front = n;
                cout << "Patient Enqueued!" << endl;
            }

            else 
            {
                // minimum priority
                if (head->priority > n->priority)
                {
                    n->next = head;
                    head->prev = n;
                    head = n;
                    cout << "Patient Enqueued!" << endl;
                }
                
                // maximum priority
                else
                {
                    if (front->priority < n->priority)
                    {
                        n->prev = front;
                        front->next = n;
                        front = n;
                        cout << "Patient Enqueued!" << endl;
                    }

                    //Priority in between
                    else
                    {
                        if ((head->priority < n->priority) && (head->next->priority > n->priority))
                        {
                            head->next->prev = n;
                            n->next = head->next;
                            head->next = n;
                            n->prev = head;
                            cout << "Patient Enqueued!" << endl;
                        }
                        else
                        {    
                            Node* ptr = front;
                            Node* prevptr = ptr->prev;
                            while (!(n->priority > prevptr->priority) && (n->priority < ptr->priority))
                            {
                                ptr = ptr->prev;
                                prevptr = prevptr->prev;
                            }
                            prevptr->prev = n;
                            ptr->next = n;
                            n->prev = ptr;
                            n->next = prevptr;
                            cout << "Patient Enqueued!" << endl;
                        }
                    }
                }              
            }
        }   
    }

    // Dequeue Function
    void dequeue()
    {
        if (head == NULL)
        {
            cout << "Error! Queue is empty." << endl;
        }
        
        else
        {
            string deqValue;
            if (head->next == NULL)
            {
                deqValue = head->name;
                head = NULL;
                front = NULL;
                cout << "Patient Dequeued!" << endl;
                
            }
            else
            {
                deqValue = front->name;
                front = front->prev;
                front->next = NULL;
                cout << "Patient Dequeued!" << endl;
            }
            
        } 
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "Error! Queue is empty" << endl;
        }
        
        else
        {
            cout << endl << "---Name | Priority---" << endl << endl;
            Node* ptr = front;
            while (ptr != NULL)
            {
                cout << "(" << ptr->name << " | " << ptr->priority << ")" << "<-->";
                ptr = ptr->prev;
            }  
        }
    }
};

int main(){
    priorityQueue q1;

    int option;
    int priority;
    string name;
    cout << "--------------------------------" << endl;
    cout << "Hospital Queue Management System" << endl;
    cout << "--------------------------------" << endl;
    cout << "\nWelcome!" << endl;
    do
    {
        cout << "\nEnter an option number" << endl;
		cout << "1. Enqueue" << endl;
		cout << "2. Dequeue" << endl;
		cout << "3. Display Queue" << endl;
		cout << "4. Clear Screen" << endl;
        cout << "0. Exit" << endl;
		cin >> option;
        Node* n1 = new Node();
        
        switch (option)
        {
        case 0:
            cout << "--------------" << endl;
            cout << "Program Exited" << endl;
            cout << "--------------" << endl;
            break;

        case 1:
            cout << "----------------" << endl;
            cout << "Enqueue Function" << endl;
            cout << "----------------" << endl;
            cout << "Enter patient name:"<< endl;
            cin >> name;
            cout << "Enter priority: " << endl;
            cin >> priority;
            n1->priority = priority;
            n1->name = name;
            q1.Enqueue(n1);
            break;
            
        case 2:
            cout << "----------------" << endl;
            cout << "Dequeue Function" << endl;
            cout << "----------------" << endl;
            q1.dequeue();
            break;

        case 3:
            cout << "----------------" << endl;
            cout << "Display Function" << endl;
            cout << "----------------" << endl;
            q1.display();
            break;

        case 4:
            system("cls");
            break;

        default:
            cout << "Enter a valid option!" << endl << endl;
        }
    } while (option != 0 );
    return 0;    
}