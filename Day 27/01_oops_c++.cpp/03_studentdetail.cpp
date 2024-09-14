#include <iostream>
#include <string>
using namespace std;

class engineer
{
    string name[10];
    long long int number[10];
    int roll[10];
    string sec[10];
    int index;

public:
    void count(void) { index = 0; };
    void enter(void);
    void display(void);
};
void engineer ::enter(void)
{
    cout << "Enter the name of student " << index + 1 << " : ";
    cin >> name[index];
    cout << "Enter the Mobile number : ";
    cin >> number[index];
    cout << "Enter the roll number : ";
    cin >> roll[index];
    cout << "ENter the section : ";
    cin >> sec[index];
    index++;
}
void engineer ::display(void)
{
    for (int i = 0; i < index; i++)
    {
        cout << endl
             << endl
             << "**Details of student " << i + 1 << "**" << endl
             << "Name : " << name[i] << endl
             << "ROll no. " << roll[i] << endl
             << "Section : " << sec[i] << endl
             << "Mobile number : " << number[i] << endl;
    }
}
int main()
{
    engineer student;
    student.count();
    student.enter();
    // student.enter();
    // student.enter();
    // student.enter();
    student.display();
    return 0;
}