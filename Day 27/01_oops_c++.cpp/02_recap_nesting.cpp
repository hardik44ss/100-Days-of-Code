//swaping binary number 0<-->1
#include <iostream>
#include <string>
using namespace std;

class binary
{
    string s; // by default class member aare private

public:
    void read(void);//reading and geting the value
    void chkbin(void);// check if not a binary number
    void swapnumb(void);//changing number
    void display(void);
};

void binary :: read(void)
{
    cout << "Enter a binary number :";
    cin >> s;
    // strng header file needed
}

void binary :: chkbin(void)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) != '0' && s.at(i) != '1')
        {
            cout << "Incorrect binary format" << endl;
            exit(0);
        }
    }
}

void binary ::swapnumb(void)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) == '0')
        {
            s.at(i) = '1';
        }
        else
        {
            s.at(i) = '0';
        }
    }
}
void binary ::display(void)
{
    swapnumb(); // this is called nesting
    for (int i = 0; i < s.length(); i++)
    {
        cout << s.at(i);
    }
    cout << endl;
}

int main()
{
    binary b;
    b.read();
    b.chkbin();
    // b.swapnumb(); this call can be done by display in their fuction
    cout << "Displaying you binary number : ";
    b.display();
    return 0;
}