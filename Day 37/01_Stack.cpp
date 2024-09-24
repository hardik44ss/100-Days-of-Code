/*
Stack : Linear Data Structure which follows LIFO (Last In First Out) principle.
i,e. : Plates in a canteen, Books in a stack, etc.
Operations:
    1. Push: Insert an element at the top of the stack.     stack.push(10);
    2. Pop: Remove an element from the top of the stack.    stack.pop();
    3. Top: Get the top element of the stack.(Peek element) stack.top();
    4. Empty: Check if the stack is empty.                  stack.empty(); (T/F)
    5. Size: Get the number of elements in the stack.       stack.size();
*/
#include<iostream>
#include<stack>
using namespace std;

int main () 
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "\nTop Element: " << s.top() << endl;
    cout << "Size: " << s.size() << endl;
    cout << "Empty or Not: " << s.empty() << endl;

    s.pop();
    
    cout << "\nTop Element: " << s.top() << endl;
    cout << "Size: " << s.size() << endl;
    cout << "Empty or Not: " << s.empty() << endl;

    return 0;
}