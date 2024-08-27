#include<iostream>
#include<vector>
using namespace std;

/*GCD = (a-b,b)
      = (a%b , b)

-Relation gcd & lcm
    gcd(a,b)*lcm(a,b) = a*b

*/

int gcd(int a , int b){
    if(a==0)
        return b;
    if(b==0)
        return a;
    while(a!=b){
        if(a>b)
            a = a - b;
        else
            b = b - a;
    }
    return a;
}

int main () 
{
    int a,b;
    cin>>a>>b;
    int gCd = gcd(a,b);
    cout<<"GCD of "<<a<<" and "<<b<<" is "<<gCd<<endl;
    return 0;
}