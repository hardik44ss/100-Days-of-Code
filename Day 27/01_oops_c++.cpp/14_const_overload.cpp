#include <iostream>
using namespace std;

class complex
{
    int a, b;
public:
    complex(){ // automatically detact constructer
        a = 0;
        b = 0;
    }
    complex(int x){
        a = x;
        b = 0;
    }
    complex(int x, int y){
        a = x;
        b = y;
    }
    void display(void){
        cout << "The value of complex number is " << a << " + " << b << "i" << endl;
    };
};
int main()
{
    complex c1, c2(4), c3(4, 5); // COnstructor overloading
    c1.display();
    c2.display();
    c3.display();
    return 0;
}