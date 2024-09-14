#include<iostream>
using namespace std;

class student 
{
    int id;
    int pocketmonney;
    public:
        void setid(void ){
            pocketmonney=69;
            cout<<"Enter the id of the student : ";
            cin>>id;
        }
        void displayid(void){
            cout<<"The id of the student is : "<<id<<endl;
        }
};
int main(){
    student std11[4];
    for (int i = 0; i < 4; i++)
    {
        std11[i].setid();
        std11[i].displayid();
    }

    return 0;
}