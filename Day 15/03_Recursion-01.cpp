#include<iostream>
using namespace std;

int factorial (int n ){
    if(n==0){
        return 1;
    }
    return n*factorial(n-1);
}

int main () 
{
    int n=5;
    cout<<"Factorial of 5 : "<<factorial(n);
    return 0;
}