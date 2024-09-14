#include<iostream>
using namespace std;

class Base{
    int data1; // not inheritable
    public:
        int data2;
        void setData(); // If it is private then der.setData(); can;t be called from main()
        int getData1() ;
        int getData2() ;
};

void Base::setData(){
    data1 = 10;
    data2 = 20;
}
int Base :: getData1(){
    return data1;
}
int Base :: getData2(){
    return data2;
}

/*class Derived : private  Base --> setdata cant called /\/we can
                                    call setdata inside out process m_function*/ 
class Derived : public  Base { 
    public:
        int data3;
        void process();
        void display();
};

void Derived :: process(){
    data3 = data2 * getData1(); // data2 is public so this can be directlty accesed
}
void Derived :: display(){
    cout << "data1 = " << getData1() << endl;
    cout << "data2 = " << data2 << endl;
    cout << "data3 = " << data3 << endl;

}

int main () 
{
    Derived der;
    der.setData();
    der.process();
    der.display();
    return 0;
}