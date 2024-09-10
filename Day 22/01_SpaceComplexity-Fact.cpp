// Space complexity : space required as a funciton on input n 
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
/*Space COmplexity : 
        factorial(5) -> factorial(4) -> factorial(3) -> factorial(2) -> factorial(1) -> factorial(0)
        5*4*3*2*1*1 = 120
        Space complexity : k*O(1)+O(1) = O(k) = O(n)
*/