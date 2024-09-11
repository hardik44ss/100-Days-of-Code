#include<iostream>
using namespace std;

int trailingZeros(int n){
    // return n/3125+n/625+n/25 +n/5;
    int zeroCount = 0;
        while (n > 0) {
            n /= 5;
            zeroCount += n;
        }
        return zeroCount;
}

int main () 
{
    int n ;
    cin>>n;
    cout<<trailingZeros(n)<<endl;
    return 0;
}