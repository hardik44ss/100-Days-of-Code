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


    Recurance relation: 
        T(n) = T(n-1) + T(n-2) + O(1)
        T(1) = O(1)
        T(0) = O(1)

        T(n)   = T(n-1) + T(n-2) + O(1)
        T(n-1) = T(n-2) + T(n-3) + 2*O(1)
        T(n-2) = T(n-3) + T(n-4) + 2*(2*O(1))
        .
        .
        .
        T(1)   = O(1)
        T(0)   = O(1)
    Sum  -----------------------
        T(n) = O(2^n)

        T(n) = O(2^n)
        Space complexity : O(n)


T(5) = T(4) + T(3) + O(1)
T(4) = T(3) + T(2) + O(1)
T(3) = T(2) + T(1) + O(1)
T(2) = T(1) + T(0) + O(1)
T(1) = O(1)
T(0) = O(1)
Sum  -----------------------
T(5) = 2^5
*/