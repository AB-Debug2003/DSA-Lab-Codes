#include<iostream>
#include<string>
using namespace std;

class PriorityQueue{
    int front,rear,i,count;
    int arr[5];

public:
    PriorityQueue()
    {
        front = -1;
        rear = -1;
        i = 0;
        for (int i = 0; i < 5; i++)
        {
            arr[i] = 0;
        } 
    }

    bool isEmpty()
    {
        if (front == -1 && rear == -1)
        {
            return true;
        }

        else
        {
            return false;
        }  
    }

    bool isFull()
    {
        if (rear == 4)
        {
            return true;
        }

        else
        {
            return false;
        }
    }

    void enQueue(int item)
    {
        if (isFull())
        {
            cout << "Queue is Full" << endl;
        }
        
        else if (isEmpty())
        {
            front++;
            rear++;
            arr[rear] = item;
            cout << "Value Enqueued!" << endl;
            count++;
        }

        else if (item >= arr[rear])
        {
            rear++;
            arr[rear] = item;
            cout << "Value Enqueued!" << endl;
            count++;
        }

        else
        {
            i = rear;
            while (i != -1)
            {
                if (arr[i] > item)
                {
                    arr[i+1] = arr[i];
                    i--;
                }
                
                else
                {
                    arr[i+1] = item;
                    rear++;
                    cout << "Value Enqueued!" << endl;
                    break;
                    count++;
                }
            }
        }
    }

    int deQueue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty!" << endl;
        }
        
        else
        {
            int deqVal = arr[front];
            i = front;
            while (i != rear)
            {
                arr[i] = arr[i+1];
                i++;
            }
            rear--;
            count--;
            return deqVal;
        }
    }

    int itemCount()
    {
        return count;
    }

    void display()
    {
        cout << "All values in Queue are" << endl;
        for (int i = 0; i < 5; i++)
        {
            cout << arr[i] << "  ";
        }
    }
};

int main(){
    PriorityQueue p1;
    int val,option;
    do
    {
        cout << "\nWhat operation do you want to perform ?" << endl;
		cout << "1. Enqueue()" << endl;
		cout << "2. Dequeue()" << endl;
		cout << "3. isEmpty()" << endl;
		cout << "4. isFull()" << endl;
		cout << "5. count()" << endl;
		cout << "6. Display()" << endl;
		cout << "7. Clear Screen" << endl;
        cout << "0. Exit" << endl;
		cin >> option;

        switch (option)
        {
        case 0:
            cout << "Program Exited" << endl;
            break;
        
        case 1:
            cout << "Enqueue Operation \nEnter a value to Enqueue: ";
            cin >> val;
            p1.enQueue(val);
            break;

        case 2:
            cout << "Dequeued Value: " << p1.deQueue() << endl <<endl;
            break;

        case 3:
            if (p1.isEmpty())
            {
                cout << "Queue is Empty" << endl << endl;
            }

            else
            {
                cout << "Queue is Not Empty" << endl << endl;
            }
            break;
            
        case 4:
            if (p1.isFull())
            {
                cout << "Queue is Full" << endl << endl;
            }

            else
            {
                cout << "Queue is Not Full" << endl << endl;
            }
            break;

        case 5:
            cout << "Count: " << p1.itemCount() << endl << endl;
            break;

        case 6:
            p1.display();
            cout << endl << endl;
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