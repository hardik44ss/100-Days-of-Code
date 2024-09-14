#include <iostream>
using namespace std;

class student
{
    int id;
    static int count; // Default value 0
    //count is the static member of the class
public:
    void setdata(void){
        cout<< "Enter the id of the student "<<count<<" : ";
        cin >> id;
        count++;
    }
    void getdata(void){
        cout<<"The id number of student "<<count<<" is : "<< id <<endl;
        
    }
    static void getcount(void){
        cout<<"The value of count is : "<<count<<endl;
        //isme sirf yehi print hoga 
        //cout<<id; throws error
    }
};
int  student :: count;// count is int so declare student as int
 // here count value can be change
int main()
{
    student:: getcount();

    student hardik,mohit,sahil;
    hardik.setdata();
    hardik.getdata();
    student :: getcount();

    mohit.setdata();
    mohit.getdata();
    student :: getcount();
    
    sahil.setdata();
    sahil.getdata();
    student :: getcount();
    

    return 0;
}
