#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int>& inputStack, int count, int n) {
   // Base case
   if (count == n / 2) {
      inputStack.pop();
      return;
   }

   // Store the number 
   int num = inputStack.top();
   inputStack.pop();

   // Recursive call
   solve(inputStack, count + 1, n);

   // Push the number back after the middle element is removed
   inputStack.push(num);
}

void deleteMiddle(stack<int>& inputStack, int N) {
   int count = 0;
   // Call the solve function without 'void' keyword
   solve(inputStack, count, N);
}

void print(stack<int> inputStack) {
   while (!inputStack.empty()) {
      cout << inputStack.top() << " ";
      inputStack.pop();
   }
   cout<<endl;
}


int main () 
{
    stack<int> inputStack;
    inputStack.push(1);
    inputStack.push(2);
    inputStack.push(3);
    inputStack.push(4);
    inputStack.push(5);

    //Printing before
    cout << "Before: ";
    print(inputStack);
    deleteMiddle(inputStack, inputStack.size());
    
    //Printing after
    cout << "After: ";
    print(inputStack);


    return 0;
}