#include<iostream>
using namespace std;
int main(){
    int t ;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s="aeiou";
        string ans = "";
        for(int i =0 ;i<n;i++){
            ans += s[(i*5)/n];
        }
        cout<<ans<<endl;
    }
}