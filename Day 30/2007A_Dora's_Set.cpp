#include<iostream>
#include<algorithm>
using namespace std;

int findNumbers(int a, int b)
{
    int count = 0;
    for(int i = a; i <= b-2; i++)
    {
        // Check if gcd(a,b) = gcd(b,c) = gcd(a,c) = 1   
        if(__gcd(i, i+1) == 1 && __gcd(i+1, i+2) == 1 && __gcd(i, i+2) == 1)
        {
            count++;
        }
    }
    return count;
}

int main () 
{
    int n;
    cin >> n;
    while(n--)
    {
        int a, b;
        cin >> a >> b;
        cout << findNumbers(a, b) << endl;
    }
    return 0;
}
