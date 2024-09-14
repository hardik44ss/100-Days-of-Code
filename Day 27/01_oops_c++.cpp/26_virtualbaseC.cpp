#include<iostream>
using namespace std;

class Stdudent{
    protected:
        int id;
    public:
        void setid(int num){
            id=num;
        } 
        void printid(){
            cout<<"Student Id is : "<<id<<endl;
        }
};
class Marks: virtual public Stdudent {
    protected:
        float math , cpp;
    public:
        void setmarks(float m, float n){
            math=m;
            cpp =n ;
        }
        void printmarks(){
            cout<<"Your marks in math is : "<<math<<endl;
            cout<<"Your marks in C++ is : "<<cpp<<endl;
        }
};

class Sports: virtual public Stdudent {
    protected:
        float score;
    public:
        void setscore(float s ){
            score=s;
        }
        void printscore(){
            cout<<"Your score in sports is : "<<score<<endl;
        }
};

class Result:public Marks, public Sports{
    float total;
    public:
        void display(){
            total=score+math+cpp;
            printid(); 
            printmarks();
            printscore();
            cout<<"Total of all subjects are : "<<total<<endl;
        }
};

int main () {
    Result hardik;
    hardik.setid(44); // Here is ambiguity resolved
    hardik.setmarks(92.8 , 93.6);
    hardik.setscore(97);
    hardik.display();
    return 0;
}

