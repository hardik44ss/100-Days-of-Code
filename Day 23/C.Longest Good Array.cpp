#include <iostream>
using namespace std;

long long int maxi(long long int a , long long int b){
    long long int sum = 0;
    long long int i =0;
    while(a<=b){
        sum+=1;
        i++;
        a= a+i;
    }
    return sum;
}


int main() {
    int n;
    cin>>n;
    while(n--){
        long long int a,b; 
        cin>>a>>b;
        
        cout<<maxi(a,b)<<endl;
    }
    return 0;
}