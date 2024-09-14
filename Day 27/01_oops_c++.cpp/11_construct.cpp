#include<iostream>
using namespace std;
class complex 
{
    int a,b;
    public :
        complex(void);//Constructer declararation
///// invoke cnstructer with same name 
        void display(){
            cout<<"THe value of a and b is "<<a<<" and "<< b ;
        }
};
complex::complex(void){// no return type
    a=12;
    b=14;
}
int main(){ 
    complex c1;// constructer automatically invoked 
    c1.display(); 
    
    return 0;
}
/* Characterstics:->
1. THey should be declared in public sextion
2. They are automatically invoked whenever the object is declared
3. Constructer is a special member finction with the same name as of the class
4. It is used to initialize the objects of its class 
5. It is automatically invoked whenever an object is created
6. We cant refer to the address
*/