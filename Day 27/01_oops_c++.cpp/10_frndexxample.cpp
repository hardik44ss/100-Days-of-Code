#include <iostream>
using namespace std;
class c2;
class c1{
    int val;
public:
    void intdata(int a)
    {
        val = a;
    }
    void display(void)
    {
        cout << val << endl;
    }
    friend void exchange(c1 &, c2 &);
};
class c2{
    int value;
public:
    void intdata(int b)
    {
        value = b;
    }
    void display(void)
    {
        cout << value << endl;
    }
    friend void exchange(c1 &, c2 &);
};
void exchange(c1 &x, c2 &y){
    int swap = x.val;
    x.val = y.value;
    y.value = swap;
}
int main()
{
    c1 oc1;
    c2 oc2;

    oc1.intdata(22);
    oc2.intdata(44);
    exchange(oc1, oc2);
    cout << "The value after exhange c1 : ";
    oc1.display();
    cout << "The value after exhange c2 : ";
    oc2.display();
    return 0;
}