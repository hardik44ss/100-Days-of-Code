#include<iostream>
using namespace std;

// AMBIGUITY : The quality of being open to more than one interpretation; inexactness:
class Base1 {
    public:
        void samefn(){
            cout<<"\nVoid function of Base 1"<<endl;
        }
};
class Base2 {
    public:
        void samefn(){
            cout<<"Void function of Base 2";
        }
};
class Derived : public Base1 , public Base2 {
    public:
        void samefn(){
            Base1::samefn(); // THis is called as ambiguity resolution
            //WHen two fuction is same in the base blass then we have to specify that which functin we want to use
        }
}; 
int main () 
{
    Derived d;
    d.samefn();
    return 0;
}