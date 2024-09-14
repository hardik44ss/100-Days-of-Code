#include<iostream>
#include<math.h>
using namespace std;
/*
Create 2 classes:
    1. SimpleCalculator - Takes input of 2 numbers using a utility function and performs +, -, *, / and displays the results using another function.
    2. ScientificCalculator - Takes input of 2 numbers using a utility function and performs any four scientific operations of your choice and displays the results using another function.

    Create another class HybridCalculator and inherit it using these 2 classes:
    Q1. What type of Inheritance are you using?
    Q2. Which mode of Inheritance are you using?
    Q3. Create an object of HybridCalculator and display results of the simple and scientific calculator.
    Q4. How is code reusability implemented?
*/

class Simplecalc {
    public:
        float a,b;
        void setsima(void){
            cout<<"Enter number a : ";
            cin>>a;
            cout<<"Enter number b : ";
            cin>>b;
        }
        float returna(){
            return a;
        }
        float returmb(){
            return b;
        }
         
        void Simpcalcutor(){
            cout<<"\nAddition is : "<<a+b;
            cout<<"\nSubtraction is : "<<a-b;
            cout<<"\nMultiplication is : "<<a*b;
            cout<<"\nDivision is : "<<a/b<<endl;
        }
};
class  Scientificcalc : public Simplecalc{
    public:
        float x;
        float y;
        void setxy(){
            x=returna();
            y=returmb();   
        } 
        void scicalc(){
            cout<<"\nAddition is : "<<x+y;
            cout<<"\nSine of x and y  is : "<<sin(x)<<", "<<sin(y);
            cout<<"\nCosine of x and y is: "<<cos(x)<<", "<<cos(y);
            cout<<"\nPower x to y is  : "<<pow(x,y);
            cout<<"\nExponential of x and y  : "<<exp(x)<<", "<<exp(y);
            cout<<"\nNegative Exponential of x and y  : "<<expm1(x)<<", "<<expm1(y)<<endl;
        }
};

class  HybridCalculator :public Scientificcalc {
    public:
        HybridCalculator(){
            cout<<"\n\nOutput of Simplecalculator : "<<endl;
            Simpcalcutor();
            cout<<"\n\nOutput of Scintificcalculator : "<<endl;
            scicalc();
        }
};

int main(){
    Simplecalc c1;
    c1.setsima();
    c1.Simpcalcutor();
    Scientificcalc s1;
    s1.setxy();
    s1.scicalc();
    HybridCalculator h1;
    


    return 0;
}