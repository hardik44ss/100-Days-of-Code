#include<iostream>
using namespace std;

int aRaiseB (int a, int b){
    if(b==0){
        return 1;
    }
    if(b==1){
        return a;
    }
    int mult= aRaiseB(a,b/2);
    if(b&1){
        return mult*mult*a;
    }
    else{
        return mult*mult;
    }
}

int main () 
{
    int a = 2 , b=8;
    cout <<"2^8 : " <<aRaiseB(a,b)<<endl;
    return 0;
}