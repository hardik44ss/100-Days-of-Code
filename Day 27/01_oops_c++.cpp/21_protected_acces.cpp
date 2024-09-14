#include<iostream>
using namespace std;

class Base{
    protected:
        int a=44; 
    private:
        int b;
};

class Derived: protected Base{
    /* a = protrected
        : a can be accessed inside public but not outside (d.a)
    */
    public:
    void showData() {
       cout << "Value of base class variable 'a' is : " << a << endl;
    }
};

int main(){
    // Base b;
    Derived d;
    // cout<<d.a; // Will not work since a is protected in both base 
    // as well as derived class
    d.showData();
    return 0;
}
/* 
                     Public Deritn  Private Derition  Protected Derivtn
                                                           
Private members   :  Not Inherited  Not Inherited     Not Inherited                                        
Protected members :  Protected      Private           Protected                      
Public members    :  Public         Private           Protected
*/
                  
                                                

