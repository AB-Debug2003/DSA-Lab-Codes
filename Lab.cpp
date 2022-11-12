#include<iostream>
#include<string>
using namespace std;

void CallbyValue_Swap(int a, int b)
{
    cout << "Before Swapping" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    int temp = a;
    a = b;
    b = temp;
    cout << "After Swapping by Call by value" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}

void CallbyReference_Swap(int* a, int* b)
{
    cout << "Before swapping " << endl;
    cout << "a = " << *a << endl;
    cout << "b = " << *b << endl;
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    cout << "After swapping by Call by reference " << endl;
    cout << "a = " << *a << endl;
    cout << "b = " << *b << endl;
}
int main(){
    int option;
    int a;
    int b;

    do
    {
        cout << "Enter an option" << endl;
        cout << "1. Swap numbers with Call By Value" << endl;
        cout << "2. Swap numbers with Call By Reference" << endl;
        cout << "0. Exit" << endl;
        
        cin >> option;
        switch (option)
        {
        case 0:
            cout << "Program Exit" << endl;
            break;
        case 1:
            cout << "Enter First Number: " << endl;
            cin >> a;
            cout << "Enter second Number: " << endl;
            cin >> b; 
            CallbyValue_Swap(a,b);
            break;
        
        case 2:
            cout << "Enter First Number: " << endl;
            cin >> a;
            cout << "Enter second Number: " << endl;
            cin >> b; 
            CallbyReference_Swap(&a,&b);
            break;

        default:
            cout << "Enter a valid option" << endl;
            break;
        }
    } while (option != 0);
    
    
    return 0;
}