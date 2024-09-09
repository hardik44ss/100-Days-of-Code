//Recurance relation
#include<iostream>
using namespace std;

int factorial(int n){
    if(n==0){
        return 1; // T(0) = 1
    }
    return n*factorial(n-1);
}

int main () 
{
    int n=5;
    cout<<factorial(n);

    return 0;
}
/*Time complexity : Write recurance relation
                
                T(n)   = T(n-1) + O(1)
                T(n-1) = T(n-2) + O(1)
                T(n-2) = T(n-3) + O(1)
                .
                .
                .
                T(1)   = T(0) + O(1)
                T(0)   = O(1)
            Sum  -----------------------
                T(n) = n*O(1)
                
                T(n) = O(n)
                Space complexity : O(n)
*/