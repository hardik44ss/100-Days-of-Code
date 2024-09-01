#include<iostream>
#include<vector>
using namespace std;

int main () 
{
    int n=44;
    cout<<"n : "<<n<<endl;

    //Address of operator
    cout<<"Address of n : "<<&n<<endl; //Hexadecimal format

    //Creating a pointer
    // int *p; Vary bad practice (Pointer declaration)

    char a ='H';

    // Type of pointer is same as variable
    char *q=&a;
    cout<<"Address of q : "<<q<<endl; //Address of a
    cout<<"Value of q : "<<*q<<endl; //Address of a

    // Type of pointer is same as variable
    int *p=&n;  
    //*p is value of n 
    cout<<"\nValue of p : " <<*p<<endl; // * : dereference variable
    cout<<"Address at p : "<<p<<endl;
    cout<<"Address of pointer p "<<&p<<endl;
    
    (*p)++; // Or n++
    
    cout<<"\nValue of p : " <<*p<<endl;
    cout<<"Address at p : "<<p<<endl;

    /*
    Size of pointer : 8 byte always (64 bit )
    Size of pointer : 4 byte (32 bit)
    */
    cout<<"\nSize of pointer : "<<sizeof(p)<<endl;
    cout<<"Size of pointer : "<<sizeof(q)<<endl;

    int *ptr = 0 ;
    // cout<<*p;  Segmentation fault : Null pointer
    int i=4;
    ptr=&i;
    cout<<"\nValue of ptr "<<ptr<<endl;
    cout<<"Address of ptr "<<*ptr<<endl;
    
    



    return 0;
}