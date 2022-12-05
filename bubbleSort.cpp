#include<iostream>
#include<string>
using namespace std;

int main(){
    int arr[10];
    cout << "Enter 10 values in array: " << endl;
    for (int i = 0; i < 10; i++)
    {
        cin >> arr[i];
    }
    
    cout << "Unsorted Array: " << endl;
    cout << "[";
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << ",";
    }
    cout << "]" << endl;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < (10-i-1); j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    
    cout << "Sorted Array: " << endl;
    cout << "[";
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << ",";
    }
    cout << "]" << endl;
    
    return 0;
}