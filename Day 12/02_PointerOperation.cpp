#include<iostream>
#include<vector>
using namespace std;

int main () 
{
    //Copying a pointer
    int num=5;
    int* p1=&num;
    int* p2=p1;
    cout<<"p1: "<<p1<<endl;
    cout<<"p2: "<<p2<<endl;
    //p2 is pointing to the same location as p1

    cout<<"*p1 : "<<*p1<<endl;
    cout<<"*p2 : "<<*p2<<endl;

    //Important concept
    int a=5;
    int *ptr = &a;
    cout<<"\nBefore , *ptr : "<<*ptr<<endl;
    (*ptr)= (*ptr)*2;
    cout<<"After , *ptr : "<<*ptr<<endl;

    cout<<"\nBefore , ptr : "<<ptr<<endl;

    ptr = ptr + 1; // 4 byte added to address

    cout<<"After , ptr : "<<ptr<<endl;

    double b = 2.0;
    double* ptr2 = &b;
    cout<<"\nBefore , ptr2 : "<<ptr2<<endl;
    ptr2= ptr2 + 1; // 8 byte will be added
    cout<<"After , ptr2 : "<<ptr2<<endl;

    ptr2= ptr2 + 2; // 16 byte will be added
    cout<<"After , ptr2 : "<<ptr2<<endl;
    return 0;
}