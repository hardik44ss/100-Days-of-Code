#include<iostream>
using namespace std;
 
class Complex{
    int a , b;
    public : 
        void setnumber(int n1,int n2){
            a=n1;
            b=n2;
        }
        friend Complex sumcomplex(Complex o1,Complex o2);
        void printnumber(){
            cout<<"Your number is "<<a<<" + "<<b<<"i"<<endl;
        }
 };
Complex sumcomplex(Complex o1,Complex o2){
    Complex o3;
    //can't acces private number untill friend fucntion called
    o3.setnumber((o1.a + o2.a),(o1.b+o2.b));
    return o3;
}

int main(){
    Complex c1,c2,sum;
    c1.setnumber(1,4);
    c1.printnumber();
    c2.setnumber(10,40);
    c2.printnumber();
    sum=sumcomplex(c1,c2);
    sum.printnumber();

    return 0;
}