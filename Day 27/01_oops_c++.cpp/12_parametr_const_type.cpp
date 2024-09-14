// Parameterized constructer
#include<iostream>
using namespace std;
class complex 
{
    int a,b;
    public :
        complex(int x,int y);//Constructer declararation
        void printnum(){
            cout<<"THe value of a and b is "<<a<<" and "<< b <<"i"<<endl;
        }

};
class graph
{
    int a,b;
    public :
        graph(int x , int y){
            a=x;
            b=y;
        };
        void display(void){
            cout <<"The value of coordinate is : ("<<a<<","<<b<<")";
        };
};
// Parameterized constructer taking two value
complex::complex(int x, int y)
{
    a=x; 
    b=y;
}

int main(){
    //Implicit call
    complex imp(2,3);
    //Explicit func
    complex exp = complex(3,4);// =exp(3,4)
     // Ek hi baat h imp == exp
    imp.printnum();
    exp.printnum();

    graph pnt(3,4);
    pnt.display();
    return 0;
}