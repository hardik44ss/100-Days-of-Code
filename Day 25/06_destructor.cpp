// destructor never takes an argument and dont return any value 
// it is impilicitly called by compiler to destroy the waste memory
/*
    -Destructor called  when object goes out of scope. or No langer need
    -**it is called at the end of its block **
*/
#include<iostream>
using namespace std;
int count =0;
class kuchbhi{
    public:
        kuchbhi(){
            count++;
            cout<<"COnstructor called for the object : "<<count<<endl;
        }
        ~kuchbhi(){ //Destructor declaration
        cout<<"Destructor Called for the object : "<<count<<endl;
        count--;
        }
};
int main (){
    cout<<"Entering Main function "<<endl;
    cout<<"Object 1  created"<<endl;
    kuchbhi ob1;
    {         
        cout<<"Entering the block "<<endl;
        cout<<"Creating two object :"<<endl;
        kuchbhi ob2,ob3;
        cout<<"Exiting the block"<<endl;
    }
    cout<<"Exiting main function"<<endl;
}
