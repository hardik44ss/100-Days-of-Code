#include<iostream>
using namespace std;

class Student {
    int id , section;
    public:
        void setdata(int a , int b){
            id=a;
            section=b;
        }
        void display(){
            cout<<"ID of the student is : "<<id<<endl;
            cout<<"Section is : "<<section<<endl;
        }
};
class P {
    int a;
    public:
        P& setdata(int a){
            this->a=a;
            return *this;
        } 
        void display(){
            cout<<"Value of a is : "<<a<<endl;
        }
};

int main () 
{
    P a;
    a.setdata(5);
    a.display();



    int size=3;
    // int* ptr=&size;
    // int* ptr= new int [5]; --> give space to store 5 integer

    Student *ptr = new Student[size]; //creating an array of objects
    Student *Temptr = ptr; //creating an array of objects

    int p,q;
    for(int i=0;i<size;i++){
        cout<<"Enter value of p : ";
        cin>>p;
        cout<<"Enter value of q : ";
        cin>>q;
        // (*ptr).setdata(p,q);
        ptr->setdata(p,q);
        ptr++;
    }
    for(int i=0;i<size;i++){
        Temptr->display();
        Temptr++;
    }
    return 0;
}