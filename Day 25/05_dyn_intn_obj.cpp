#include<iostream>
using namespace std;

class bank {
    int princple;
    int years;
    float rate;
    float returnval;
    public:
        bank(){}; // iske bina compiler confuse hoga which function to call
        bank(int p , int y, float r ){
            princple=p;
            years=y;
            rate=r;
            returnval=princple;
            for (int i=0;i<years;i++){
                returnval=returnval*(1+rate);
            }
        }
        bank(int p , int y, int R ){
            princple=p;
            years=y;
            rate=float(R)/100;
            returnval=princple;
            for (int i=0;i<years;i++){
                returnval=returnval*(1+rate);
            }
        }
        void show(){
            cout << "Principle : "<<princple<<endl;
            cout << "Years : "<<years<<endl;
            cout << "Rate : "<<rate*100<<"%"<<endl;
            cout << "Return Value of your investment : "<<returnval<<endl;
        }
};

int main () 
{
    bank b1,b2; // For this we declare the bank(){}
    int p,y;
    int R;
    float r;

    cout<<"Enter principle amount : ";
    cin>>p;
    cout<<"Enter number of years : ";
    cin>>y;
    cout<<"Enter rate in fraction : ";
    cin>>r;
    b1 = bank(p,y,r);
    b1.show();

    cout<<"Enter principle amount : ";
    cin>>p;
    cout<<"Enter number of years : ";
    cin>>y;
    cout<<"Enter rate in % : ";
    cin>>R;
    b2=bank(p,y,R);
    b2.show();
    return 0;
}