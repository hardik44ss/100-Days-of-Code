#include<iostream>
using namespace std;

//Return by reference : Bad practice
// int& func(int a){ 
//     int num = a;  -> Local variable
//     int& ans = num;  -> local reference variable
//     return ans;  -> returing reference of local variable 
// }       => Generate error

void update1(int n){ 
    n= n+2;
}//Pass by value : Copy created

void update2(int &n){
    n= n+2;
}//Pass by reference : same memory used , name different used

int main () 
{
    //Reference variable : Different names of same entity
    // --Same memory : different names
    int a=5;
    int &b = a; 
    cout<<"Value of a : "<<a<<endl;
    cout<<"Value of b : "<<b<<endl;
    cout<<"\nAddress of a : "<<&a;
    cout<<"\nAddress of b : "<<&b;

    cout<<"\n\nPrint ++a : "<< ++a <<endl;
    cout<<"Print ++b : "<<++b<<endl<<endl;

    //--------WHY----------//
    int n=6;
    cout<<"Before n : "<<n<<endl;
    update1(n);
    cout<<"After Pass by Value, n : "<< n<<endl;
    update2(n);
    cout<<"After Pass by Reference, n : "<< n<<endl;

    return 0;
}