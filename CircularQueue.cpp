#include<iostream>
#include<string>
using namespace std;

class circularQueue{
    int front,rear;
    int arr[5];

public:
    circularQueue()
    {
        front = -1;
        rear = -1;
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

    void enQueue(int val)
    {
        if (isFull())
        {
            cout << "Error! Queue is Full" << endl;
        }
        
        else
        {
            front = 0;
            rear++;
            arr[rear] = val;
            cout << "Value Enqueued!" << endl;
        }
    }

    int deQueue()
    {
        if (isEmpty())
        {
            cout << "Error! Queue is Empty" << endl;
        }

        else if(front == rear)
        {
            arr[front] = 0;
            front--;
            rear--;
        }

        else
        {
            int deqVal = arr[front];
            int rearVal = arr[rear];
            arr[5] = 0;
            for (int i = 0; i < rear+1; i++)
            {
                arr[i] = arr[i+1];
            }
            rear--;
            return deqVal;
        }
    }

    int count()
    {
        return(rear - front + 1);
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
    circularQueue c1;

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
            c1.enQueue(val);
            break;

        case 2:
            cout << "Dequeued Value: " << c1.deQueue() << endl <<endl;
            break;

        case 3:
            if (c1.isEmpty())
            {
                cout << "Queue is Empty" << endl << endl;
            }

            else
            {
                cout << "Queue is Not Empty" << endl << endl;
            }
            break;
            
        case 4:
            if (c1.isFull())
            {
                cout << "Queue is Full" << endl << endl;
            }

            else
            {
                cout << "Queue is Not Full" << endl << endl;
            }
            break;

        case 5:
            cout << "Count: " << c1.count() << endl << endl;
            break;

        case 6:
            c1.display();
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