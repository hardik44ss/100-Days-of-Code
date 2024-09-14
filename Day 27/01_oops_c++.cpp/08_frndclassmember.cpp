#include <iostream>
using namespace std;
// forward declaration
// we try to amke trust that Complex class is present after the calculator class
class Complex;
class calculator
{
public:
    int add(int a, int b)
    {
        return (a + b);
    }
    int sumrealcomp(Complex, Complex);
    int sumcompcomp(Complex, Complex);
};

class Complex
{
    int a, b;
    // calculator accessing indivisualy *
    // friend int calculator ::sumrealcomp(Complex, Complex);
    // friend int calculator ::sumcompcomp(Complex, Complex);
    // Aliter : Declaring the entire claculator class as a friend
    friend class calculator;
public:
    void setnumber(int n1, int n2)
    {
        a = n1;
        b = n2;
    }
    void printnumber()
    {
        cout << "Your number is " << a << " + " << b << "i" << endl;
    }
};
int calculator ::sumrealcomp(Complex o1, Complex o2)
{
    return (o1.a + o2.a);
}
int calculator ::sumcompcomp(Complex o1, Complex o2)
{
    return (o1.b + o2.b);
}

int main()
{
    Complex o1, o2;
    o1.setnumber(1, 2);
    o2.setnumber(3, 4);
    calculator calc;
    int result = calc.sumrealcomp(o1, o2);
    int resultc = calc.sumcompcomp(o1, o2);
    cout << "The sum of real numbers  is : " << result << endl;
    cout << "The sum of complex numbers  is : " << resultc << endl;
    return 0;
}