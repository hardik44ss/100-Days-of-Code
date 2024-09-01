#include <iostream>
using namespace std; 

int main() {
    int firstvalue = 5, secondvalue = 15;
    char thirdvalue = 'a';

    int *p1 = & firstvalue; // p1 = address of firstvalue
    int *p2 = & secondvalue; // p2 = address of secondvalue 
    char*p3 = & thirdvalue; // p3 = address of thirdvalue

    * p1 = 10; // value pointed to by p1 = 10
    * p2 = * p1; // value pointed to by p2 = value pointed to by p1
    p1 = p2; // p1 = p2 (value of pointer is copied)
    * p1 = 20; // value pointed to by p1 = 20
    * p3 = 'b'; // value pointed to by p3 = ‘b ’
    cout << "firstvalue is " << firstvalue << endl;
    cout << "secondvalue is " << secondvalue << endl;
    cout << "thirdvalue is " << thirdvalue << endl;

//TYpes of pointer
    // Null Pointer ------------
    int * ptr = NULL;
    cout << "The value of ptr is " << ptr;


    //DOuble pointer---------
    int a = 10;
    int * p = & a; //pointer
    int ** q = & p; //pointer-to-pointer

    /* Next three statements will print same value i.e. address of a */
    cout << & a << endl;
    cout << p << endl;
    cout << * q << endl;

    /* Next two statements will print same value i.e. address of p */
    cout << & p << endl;
    cout << q << endl;

    /* Next three statements will print same value i.e. value of a */
    cout << a << endl;
    cout << * p << endl;
    cout << ** q << endl;


    //Void pointer
    void * voidPt;
    // cout << "Address where the void pointer is pointing " << voidPt <<  endl; //Garbage Value
    int i = 10;
    // assign int address to void
    voidPt = & i;
    cout << "Address of variable i " << & i << endl;
    cout << "Address where the void pointer is pointing " << voidPt <<  endl;

/*
    //Wild pointer
    int * wPtr; 
    int var = 10;
    wPtr = & var;  p is not a wild pointer now
    * wPtr = 12;  This is fine. Value of a is changed 

    //Dangling Pointer
    int * fun() {
        int x = 10;
        return &x;
    }
    int main() {
        int * p = fun();
        // p points to something which is not valid anymore 
        cout << * p;
        return 0;
    }


*/
    return 0;
}