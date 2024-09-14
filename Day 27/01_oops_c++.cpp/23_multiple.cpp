#include<iostream>
using namespace std;

class Base1 {
    protected:
        int a;
    public:
        void seta(int int1){
            a=int1;
        }
};
class Base2 {
    protected:
        int b;
    public:
        void setb(int int2){
            b=int2;
        }
};
class Derived : public Base1,public Base2{
    public:
        void display(void){
            cout<<"Value of Base 1 int : "<<a<<endl;
            cout<<"Value of Base 2 int : "<<b<<endl;
            cout<<"Value of Base1int + Baseint2 : "<<a+b<<endl;
        }
};

int main () 
{
    Derived d;
    d.seta(44);
    d.setb(88);
    d.display();
    return 0;
}