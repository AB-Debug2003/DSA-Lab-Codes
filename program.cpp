#include<iostream>
#include<string>
#include<stack>
using namespace std;

void printStack(stack<int> s)
{
    cout << "[";
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << "]" << endl;
}

int main(){
    stack<int> stack;
    stack.push(12);
    stack.push(2);
    stack.push(11);
    cout << stack.size() << endl;
    cout << stack.top() << endl;
    stack.emplace(6);
    printStack(stack);
    cout << stack.top() << endl;
    

    return 0;
}