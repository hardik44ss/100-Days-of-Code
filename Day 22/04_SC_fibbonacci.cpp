#include<iostream>
using namespace std;

//Fibbonacci series
int fib(int n){
    if(n==1 || n==0){
        return n;
    }
    return fib(n-1) + fib(n-2);
}

int main () 
{
    int n=9;
    cout<<fib(n);
    return 0;
}
/*
                   fibonacci(5)                         : 1
             /               \                          
        fibonacci(4)        fibonacci(3)                : 2
        /         \           /         \
  fibonacci(3)  fibonacci(2) fibonacci(2) fibonacci(1)  : 2^2
   /      \        /   \         /   \
fibonacci(2) fibonacci(1) fibonacci(1) fibonacci(0)     : 2^3
   /   \         /   \
 /   \
fibonacci(1) fibonacci(0)                                :2^4

1. Identify the base case:
   - The base case is when n is 0 or 1.
   - Space complexity for base case: O(1)
2. Analyze space used by local variables:
   - int fib : O(1)
3. Analyze space used by function call stack:
    - fib(n-1) + fib(n-2) + O(1)

Space : n*O(1) + O(1)
Space complexity : O(n)
*/
   
   
