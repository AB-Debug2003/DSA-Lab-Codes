#include<iostream>
#include<string>
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
        int lowest=1, highest=index;
        int range=(highest-lowest)+1;
        random_integer = lowest + int(range*rand()/(RAND_MAX + 1.0));
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