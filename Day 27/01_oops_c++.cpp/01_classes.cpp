#include<iostream>
using namespace std;

class student 
{
    private:
        int a,b,c;
        // by default class member are private

    public:
        int d,e;
        void setData(int a1,int b1,int c1);
        void getData(){
            cout<<"The value of a is : "<<a<<endl;
            cout<<"The value of b is : "<<b<<endl; 
            cout<<"The value of c is : "<<c<<endl;
            cout<<"The value of d is : "<<d<<endl;
            cout<<"The value of e is : "<<e<<endl;
        }   
};

void student :: setData(int a1 , int b1, int c1){
    a=a1;
    b=b1;
    c=c1;
}

int main(){
    student hardik;
   // hardik.a =445; -> a is inaccessible it is private
    hardik.d =44; // d,e are the private function so they can accessed outside the scope of class
    hardik.e =30;
    hardik.setData(1,2,3);
    hardik.getData();

    return 0;
} 