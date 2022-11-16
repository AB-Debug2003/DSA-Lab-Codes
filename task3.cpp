#include<iostream>
using namespace std;

int main(){
    int num;
    cout << "Enter a number: " << endl;
    cin >> num;
    int digits = 0;

    while (num > 0)
    {
        num = num/10;
        digits += 1;
    }
    cout << "Digits = " << digits << endl;
    return 0;
}