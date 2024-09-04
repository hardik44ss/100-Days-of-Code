#include<iostream>
using namespace std;

void sayDigits(int n){
    string arr[10] = {"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
    if(n==0){
        return ;
    }
    sayDigits(n/10);
    cout<<arr[n%10]<<" ";
}

int main () 
{
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    sayDigits(n);
    return 0;
}