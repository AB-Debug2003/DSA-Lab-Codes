#include<iostream>
#include<string>
using namespace std;

int main(){
    int arr[10];
    bool flag;
    for (int i = 0; i < 10; i++)
    {
        cout << "Enter element " << i+1 <<" of array: ";
        cin >> arr[i];
        cout << endl;
    }
    
    cout << "Unsorted Array: " << endl;
    cout << "[";
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i];
        if (i!=9)
        {
            cout << ",";
        }
    }
    cout << "]" << endl;

    for (int i = 0; i < 10; i++)
    {
        flag = false;
        for (int j = 0; j < (10-i-1); j++)
        {
            if (arr[j] > arr[j+1])
            {
                flag = true;
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        if (flag == false)
        {
            break;
        }
    }
    
    cout << "Sorted Array:" << endl;
    cout << "[";
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i];
        if (i != 9)
        {
            cout << ",";
        }
    }
    cout << "]" << endl;

    return 0;
}