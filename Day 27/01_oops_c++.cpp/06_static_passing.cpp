#include<iostream>
using namespace std;

class complex {
    int a;
    int b;
    public:
        void setdata(int num1, int num2){
            a=num1;
            b=num2;
        }
        void setsum(complex ob1,complex ob2){
            a=ob1.a+ob2.a;
            b=ob1.b+ob2.b;
        }
        void printnum(){
            cout<<"YOur complex number is "<<a<<"+"<<b<<"i"<<endl;
        }

};
int main(){
    complex c1,c2,c3;
    c1.setdata(3,4);
    c1.printnum();

    c2.setdata(1,2);
    c2.printnum();
    
    c3.setsum(c2,c1);
    c3.printnum();

    return 0;
}