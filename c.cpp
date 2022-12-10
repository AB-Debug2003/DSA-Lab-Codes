#include<iostream>
using namespace std;

int swap(int &x, int &y){
    int temp = x;
    x = y;
    y= temp;
}

int main(){
    int num1 = 6, num2 = 3;

    swap(num1, num2);
    cout << num1 << endl;
    cout << num2 << endl;

    return 0;
}
