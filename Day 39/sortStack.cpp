#include<iostream>
#include<stack>
using namespace std;

void sortedInsert(stack<int> &stack, int num) {
    //base case
    if(stack.empty() || (!stack.empty() && stack.top() < num) ) {
        stack.push(num);
        return;
    }
    
    int n = stack.top();
    stack.pop();
    
    //recusrive call
    sortedInsert(stack, num);
    
    stack.push(n);
}

void sortStack(stack<int> &stack)
{
		//base case
    	if(stack.empty()) {
            return ;
        }
    
    	int num = stack.top();
    	stack.pop();
    
    	//recursive call
    	sortStack(stack);
    
    	sortedInsert(stack, num);
}

void printStack(stack<int> s) {
    if(s.empty()) {
        cout<<endl;
        return ;
    }
    int num = s.top();
    s.pop();
    printStack(s);
    cout<<num<<" ";
    s.push(num);
}

int main () 
{
    stack<int> s;
    s.push(5);
    s.push(2);
    s.push(3);
    s.push(1);
    s.push(4);

    printStack(s);
    sortStack(s);
    printStack(s);

    return 0;
}