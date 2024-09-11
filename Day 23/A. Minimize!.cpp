#include<iostream>
using namespace std;

int main () 
{
    int t;
    cin>>t;
    while(t--){
        int a , b; 
        cin>>a>>b;
        cout<<b-a<<endl;
    }

    return 0;
}
/*
You are given two integers a and b (a≤b).
Over all possible integer values of c
 (a≤c≤b), find the minimum value of (c−a)+(b−c)
 */