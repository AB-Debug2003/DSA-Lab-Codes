#include<iostream>
#include<string>
using namespace std;

int main(){
    int arr[5] = {5,2,9,6,1};
    int min;
    for (int i = 0; i < 4; i++)
    {
        min = i;
        for (int j = i+1; j < 5; j++)
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
    
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << endl;
    }
    
    return 0;
}