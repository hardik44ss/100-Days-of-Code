#include<iostream>
using namespace std;
class simple {
    int a,b,c;
    public : 
        simple(int aa,int bb,int cv=44){
            a=aa;
            b=bb;
            c=cv;
        }
        void print(){
            cout<<"value of a and b and c is "<<a<<" "<<b<<" "<<c<<"  "<<endl;
        }
};
int main(){
    simple s(1,2);
    s.print();

    simple r(1,2,3);
    r.print();
    return 0;
}