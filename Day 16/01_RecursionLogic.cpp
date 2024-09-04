#include <iostream>
using namespace std;

/*
Components : Mandary( i. Base Case)
                    (ii. Recursive call)
           : Optional (Processing , print etc)
*/

void print(int n)
{
    if (n == 0)
    {
        cout << "Base case reached . \nGoing backward in tree" << endl;
        return;
    }

    cout << n << endl; // Heading ahead in recursion tree
    print(n - 1);
    cout << n << endl; // Going backward in recursion
}

void travel(int src, int des)
{

    cout << "Source at : " << src << endl;

    // Base case
    if (src == des)
    {
        cout << "\nDestination reached " << endl;
        return;
    }
    // Processing
    src++;
    // Recursive call
    travel(src, des);
}
int fib(int n)
{
    if (n == 0)
    {
        cout<<"Base Case , returned 0"<<endl;
        return 0;
    }
    if (n == 1)
    {
        cout<<"Base Case , returned 1"<<endl;
        return 1;
    }
    cout << n << endl; 

    int ans=   fib(n - 1) + fib(n - 2);
    cout<<"Anser : "<<ans<<endl;
    return ans;
}

int main()
{
    print(5);
    cout << endl;

    int src = 1;
    int dest = 10;
    travel(src, dest);

    cout<<"Fibbnacci 5th term "<<" : "<<fib(5);
    //0 is 0th term

    return 0;
}