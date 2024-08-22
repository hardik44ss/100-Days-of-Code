#include<iostream>
using namespace std;

int tempsol(int n ){
    int s=0;
    int e=n;
    long long int mid = s+ (e-s)/2;
    long long int ans =-1;
    while(s<=e){
        long long int square=mid*mid;
        if(square==n){
            return mid;
        }else if( square<n){  // mid = start , end = end;
            ans=mid;
            s=mid+1;
        }else{ // mid = end
            e=mid-1;
        }
        mid= s+(e-s)/2;
    }
    return ans;
}
double morePrcse(int n , int prcsn , int tempans){
    double factor=1;
    double ans=tempans;
    for(int i=0;i<prcsn;i++){
        factor = factor/10;
        for(double j=ans;j*j<n;j=j+factor){
            ans=j;
        }
    }
    return ans;
}

int main () 
{
    int n;
    cout<<"Enter number n : ";
    cin>>n;
    cout<<"Temporary answer is : "<<tempsol(n)<<endl;
    cout<<"Precised answer is : "<<morePrcse(n,3,tempsol(n))<<endl;
    return 0;   
}