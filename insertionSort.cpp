#include<iostream>
#include<string>
using namespace std;

int main(){
    int arr[5] = {6,2,9,8,1};
    int key;
    int j = 0;
    for (int i = 1; i < 5; i++)
    {
        key = arr[i];
        j = i-1;
        while (j >=0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << endl;
    }
    
    return 0;
}