#include<iostream>
using namespace std;

class Y;
class X {
    int num1;
    public:
        void  get(int a){
            num1=a;
        }
    friend void add(X,Y);
};
class Y {
    int num2;
    public:
        void get(int b){
           num2=b;
        }
    friend void add(X,Y);
};

void add(X a1,Y b1){
    cout<<"sum of num1 of X and num2 of Y is : "<<a1.num1 +b1.num2;
    
};
int main(){
    X o1;
    o1.get(15);
    Y o2;
    o2.get(14);
    add(o1,o2);

    return 0;
}