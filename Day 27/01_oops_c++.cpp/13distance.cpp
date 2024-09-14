//Distance between two coordinate
#include<iostream>
#include<math.h>
using namespace std;
class second ;
class first {
    double x1,y1;
    public:
        first(void){
            cout<<"Enter the value of x and y : ";
            cin>>x1>>y1;
        }
        friend void distance(first, second);
};
class second {
    double x2,y2;
    public:
        second(void){
            cout<<"Enter the value of x and y : ";
            cin>>x2>>y2;
        }
        friend void distance(first, second);
};
void distance(first f1,second f2){
    double d=sqrt(pow(f1.x1-f2.x2,2) + pow(f1.y1-f2.y2,2));
    cout<<"\nThe Distance is = " <<d;
}
int main(){
    first obj1;
    second obj2;
    distance(obj1,obj2);

    return 0;
    
}


