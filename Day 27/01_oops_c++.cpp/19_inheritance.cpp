#include<iostream>
using namespace std;

class Employee { 
    public:
        int id ;
        float salary;
        Employee(){} // Constructer of base class impilicity called by declaration of derived class - so that when constructor declare compiler not confuse
        Employee(int inpId){
            id = inpId;
            salary = 12;
        }
        void data(){
            cout << "Employee ID :"<<id
            <<"\nEmployee Salary:"<<salary<<endl<<endl;
        }
};
class Programmer :  public Employee{
        int langcode;
    public:
        Programmer(int inpId){
            id=inpId;
            salary = 20;
            langcode=4;
        }
        void data(){
            cout << "Programmer ID :"<<id
            <<"\nProgrammer Salary:"<<salary<<endl;
            cout<<"Language Code of programmer is : "<<langcode<<endl;
        }
};

int main () 
{
    Employee Mohit(55),Hardik(44);
    Mohit.data();
    Hardik.data();
    Programmer hardik(44);
    // cout<<"Langcode "<<hardik.langcode; private member

    hardik.data();

    return 0;
}

/*
Inheritance : reusability in cpp
- a class that inherits another class is known as derived or subclass   
- the class from which it inherits is called base or superclass or parent
- overriding existing functionality
Principle -
        D R Y - Do not Repeat Yourself.
*/
