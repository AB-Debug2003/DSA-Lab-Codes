#include<iostream>
#include<string>
using namespace std;

int main(){
    int arr[5] = {};
    cout << "Enter 5 elemnts of array: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }
    
    cout << "Unsorted Array: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << endl;
    }  

    cout << endl;

    for (int i = 0; i < 4; i++)
    {
        int min = i;
        for (int j = i+1; j < 5; i++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        
        if (min != i)
        {
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }

    cout << "Sorted Array: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << endl;
    }
    
    return 0;
}