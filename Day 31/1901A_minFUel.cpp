#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main () 
{
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        for(int i =0 ;i<n-1;i++){
            a[i] = a[i+1] - a[i];
        }
        a[n-1]=2*(k-a[n-1]);
        cout<<*max_element(a.begin(), a.end())<<endl;
        
    }
    return 0;
}