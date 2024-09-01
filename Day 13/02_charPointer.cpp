#include<iostream>
using namespace std;

int main () 
{
    char temp = 'z';
    char *p = &temp;
    cout<<"Value of p : "<<p<<endl;
    char x = 'Z';
    char *pt = &x;
    cout<<"Value of x : "<<pt<<endl;

    int arr[5]={5,4,3,2,1};
    char ch[7]="Hardik";

    cout<<"Integer arr : "<<arr<<endl;
    cout<<"Character ch: "<<ch<<endl;
    //Pointer implementation
    char *ptr=&ch[0];
    cout<<"\nPointer of ch , ptr  : "<<ptr<<endl;
    cout<<"Value of ch at pointer : "<<*ptr<<endl;

    
    

    return 0;
}