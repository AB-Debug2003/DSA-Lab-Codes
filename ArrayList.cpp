#include<iostream>
#include<string>
using namespace std;

class ArrayList{
    int* arr;
    int total;
    int size;

public:
    ArrayList()
    {
        size = 5;
        arr = new int[size];
        total = 0;
    }

    bool isFull()
    {
        if (total == size)
        {
            return true;
        }
        else
        {
            return false;
        }  
    }

    bool isEmpty()
    {
        if (total == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void insert(int value)
    {
        if (isFull())
        {
            size *= 2;
            int* temp = new int[size];
            for (int i = 0; i < total; i++)
            {
                temp[i] = arr[i];
            }
            delete []arr;
            arr = temp;
            insert(value);
        }
        else
        {
            arr[total] = value;
            total++;
        }
        
    }

    int find(int val)
    {
        for (int i = 0; i < total; i++)
        {
            if (arr[i] == val)
            {
                return i;
                break;
            }
        }
        return -1;
    }

    void update(int value, int newValue)
    {
        if (find(value) != -1)
        {
            arr[find(value)] = newValue;
            cout << "Value Updated!" << endl;
        }
        else
        {
            cout << "Value Not Found" << endl;
        }
        
    }

    void remove(int value)
    {
        if (isEmpty())
        {
            cout << "List is Empty" << endl;
        }
        else
        {
            int index = find(value);
            //last value
            if (arr[index] == arr[total-1])
            {
                total--;
                cout << "Value Deleted" << endl;
            }
            else
            {
                for (int i = index; i < total-1; i++)
                {
                    arr[i] = arr[i+1];
                }
                total--;
                cout << "Value Deleted" << endl;
            }
        }
    }

    void clear()
    {
        total = 0;
        size = 5;
        delete []arr;
        arr = new int[size];
    }

    void display()
    {
        if(isEmpty())
        {
            cout << "List is Empty" << endl;
        }
        else
        {
            cout << "[ ";
            for (int i = 0; i < total; i++)
            {
                cout << arr[i] << " ";
            }
            cout << "]" << endl;
        }
    }
};

int main(){
    ArrayList a;
    a.insert(20);
    a.insert(2) ;
    a.insert(6);
    a.display();
    a.remove(2);
    a.display();
    return 0;
}