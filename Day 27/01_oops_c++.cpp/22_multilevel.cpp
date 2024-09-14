#include <iostream>
using namespace std;

class Student{
    protected:
       int roll_number;
    public:
    void set_roll_number(int r){
       roll_number = r;
    }
    void get_roll_number(){
     cout << "The roll number is : " << roll_number << endl;
    }
};

class Exam : public Student{
    protected:
        float maths;
        float physics;
    public:
        void set_marks(float m1, float m2){
        maths = m1;
        physics = m2;
        }
        void get_marks(){
        cout << "\nThe marks obtained in maths are: " << maths << endl;
        cout << "The marks obtained in physics are: " << physics << endl;
        }
};

class result : public Exam {
    float percent;
    public:
        
        void display(){
            get_roll_number();
            get_marks();
            cout<<"\nResult is : "<<(physics+maths)/2<<"%"<<endl;
        }
};
int main(){
    result hardik;
    hardik.set_roll_number(44);
    hardik.set_marks(94,92);
    hardik.display();
}
/*Note: 
    If we are inheriting B from A and C from B [A-->B-->C]
    1. A is base class for B , B is base class for C .
    2. A-->B-->C is called inheritance path
    3. 
 
 */