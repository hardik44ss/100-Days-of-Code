#include<iostream>
#include<vector>
using namespace std;

void update(int **p2) {
    // p2 = p2 + 1;
    //kuch change hoga  - NO

    *p2 = *p2 + 1;
    //kuch change hoga - YES

    // **p2 = **p2 + 1;
    //kuch change hoga - YES
}

int main () 
{
    int i=5;
    int* p1=&i;
    int** p2=&p1;
    
    cout<<"Value of i : "<<i<<endl;
    cout<<"Value of *p1 : "<<*p1<<endl;
    cout<<"Value of **p2 : "<<**p2<<endl;

    cout<<"\nAddress of i : "<<&i<<endl;
    cout<<"Value of p1 : "<<p1<<endl;
    cout<<"Value of *p2 : "<<*p2<<endl;

    cout<<"\nAddress of p1 : "<<&p1<<endl;
    cout<<"Value of p2 : "<<p2<<endl;

    cout << endl << endl;

    // cout<< "before " << i << endl;
    // cout<< "before " << p1 << endl;
    // cout<< "before " << p2 << endl;
    // update(p2);
    // cout<< "after " << i << endl;
    // cout<< "after " << p1 << endl;
    // cout<< "after " << p2 << endl;

    // cout << endl << endl;

    cout<< "before " << i << endl;
    cout<< "before " << p1 << endl;
    cout<< "before " << p2 << endl;
    update(p2);
    cout<< "after " << i << endl;
    cout<< "after " << p1 << endl;
    cout<< "after " << p2 << endl;

    // cout << endl << endl;

    // cout<< "before " << i << endl;
    // cout<< "before " << p1 << endl;
    // cout<< "before " << p2 << endl;
    // update(p2);
    // cout<< "after " << i << endl;
    // cout<< "after " << p1 << endl;
    // cout<< "after " << p2 << endl;
    // cout << endl << endl;



    return 0;
}