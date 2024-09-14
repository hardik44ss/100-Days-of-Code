#include<iostream>
using namespace std;

/*Compile-time polymorphism:
    Also known as early binding.
    Determined at compile time.
--Two types: Function overloading and Operator overloading.
*Function overloading: Multiple functions with the same name but different parameters.
*Operator overloading: Redefining operators for specific tasks.

Run-time polymorphism:

`   Also known as late binding.
    Decided at runtime.
    Achieved through virtual functions.
    Virtual function: Function in the parent class redefined in the child class using the "virtual" keyword.
*/
//POINTER TO DERIVED CLASS
class Base {
    public:
        int var_base;
        // virtual void display(){ --> By this pointer only points the self class function
        void display(){
            cout<<"\nVariable of Base CLass in BC : "<<var_base<<endl;
        }
};
class Derived : public Base{
    public:
        int var_derived;
        void display(){
            cout<<"\nVariable of Base CLass in DC : "<<var_base<<endl;
            cout<<"Variable of Derived CLass in DC : "<<var_derived<<endl;
        }
};

int main (){
    Base * ptr_base;
    Base obj_base;
    Derived obj_derived;
    // *ptr_base = &obj_derived; /-> Here pointer is Derefernced so, it shows error
    ptr_base = &obj_derived; //pointing to derived object 
    ptr_base->var_base = 34;
    ptr_base->display();
    ptr_base->var_base = 57;
    ptr_base->display();
    // Dereferencing ppoly1 and ppoly2 (with ppoly1-> and ppoly2->) is valid and allows us to access the members of their pointed objects. For example, the following two statements would be equivalent in the previous example:
    //       1 ppoly1->set_values (4,5);
    //       2 rect.set_values (4,5);

    Derived * ptr_derived;
    ptr_derived = &obj_derived;
    ptr_derived->var_base=44;
    ptr_derived->var_derived=88;
    ptr_derived->display();

    return 0;
}
