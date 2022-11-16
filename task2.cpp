#include<iostream>
using namespace std;

int main(){
    for (int i = 1; i < 6; i++)
    {
        if (i%2 != 0)
        {
            cout << "************" << endl;
        }

        else
        {
            cout << "*0*0*0*0*0*0" << endl;
        }
    }
    
    return 0;
}