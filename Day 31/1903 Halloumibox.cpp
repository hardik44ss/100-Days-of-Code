#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main () 
{
    int t;
    cin>>t;
    while(t--){
        int n , k;
        cin>>n>>k;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        //if k==1 , array has to be sorted , otherwise not possible
        if(k==1 && !is_sorted(a.begin(),a.end())){
            cout<<"No\n";
        }
        else{
            cout<<"Yes\n";
        }
             


    }
    return 0;
}