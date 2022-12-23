#include<iostream>
#include<string>
using namespace std;

void bubbleSort(int arr[])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < (5-i-1); j++)
        {
            if (arr[j]> arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void optBubbleSort(int arr[])
{
    bool flag;
    for (int i = 0; i < 5; i++)
    {
        flag = false;
        for (int j = 0; j < (5-i-1); j++)
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
}

void selectionSort(int arr[])
{
    int min;
    for (int i = 0; i < 4; i++)
    {
        min = i;
        for (int j = 1; j < 5; j++)
        {
            if (arr[j] < arr[i])
            {
                min = j;
            }
        }
        if (min != i)
        {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

void insertionSort(int arr[])
{
    int key;
    int j = 0;
    for (int i = 1; i < 5; i++)
    {
        key = arr[i];
        j = i-1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    
}

void linearSearch(int arr[], int n)
{
    bool flag = false;
    for (int i = 0; i < 5; i++)
    {
        if (arr[i] == n)
        {
            cout << "Element found at position " << i+1 << endl;
            flag = true;
            break;
        }
    }

    if (flag == false)
    {
        cout << "Element not found" << endl;
    }
}

int binarySearch(int arr[],int left, int right, int n)
{
    while (left<=right)
    {
        int mid = left + (right-left)/2;
        if (arr[mid] == n)
        {
            return mid;
        }
        
        else if(arr[mid] < n)
        {
            left = mid + 1;
        }

        else
        {
            right = mid - 1;
        } 
    }
    return -1;
}

int main(){
    int arr[5] = {4,6,2,9,7};
    optBubbleSort(arr);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << endl;
    }
    cout << binarySearch(arr,0,4,9);
    return 0;
}