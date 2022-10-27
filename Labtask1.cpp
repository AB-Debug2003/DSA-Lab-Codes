#include<iostream>
#include<string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Giveaway{
    int random_integer;
    string array[50] = {};
    int index = 0;
public:
    void input(string userInput)
    {
        array[index] = userInput;
        index ++;
    }

    void display()
    {
        cout << "All names in list are: " << endl;
        for (int i = 0; i < index; i++)
        {
            cout << array[i] << endl;
        }
    }

    void pickWinner()
    {
        random_integer = rand() % index;
        cout << "Giveaway Winner is " << array[random_integer] << endl;
    }
};

int main(){
    string userInput;   
    Giveaway g1;
    do
    {
        cout << "Enter names of participants or end/quit to quit" << endl;
        cin >> userInput;    
        g1.input(userInput);
    } 
    while (userInput != "quit" && userInput != "end");
    
    g1.display();
    g1.pickWinner();
    return 0;
}