#include "bits/stdc++.h"
#define int long long
#define uint unsigned long long
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define fr(i,n) for(int i=0; i<(n); i++)
#define rep(i,a,n) for(int i=(a); i<=(n); i++)
#define nl cout<<"\n"

// make sure to sort before applying unique // else only consecutive duplicates would be removed 
#define bin(x,y)  bitset<y>(x) 
using namespace std;
int MOD=1e9+7;      // Hardcoded, directly change from here for functions!



void modadd(int &a , int b) {a=((a%MOD)+(b%MOD))%MOD;}
void modsub(int &a , int b) {a=((a%MOD)-(b%MOD)+MOD)%MOD;}
void modmul(int &a , int b) {a=((a%MOD)*(b%MOD))%MOD;}
// ================================== take ip/op like vector,pairs directly!==================================
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
// ===================================END Of the input module ==========================================


void solve(){
    int n , k , x;
    cin>>n>>k>>x;

    
    if(x!=1){
        cout<<"YES\n";
        cout<<n<<endl;
        for(int i = 1 ; i<=n ; i++){
            cout<<1<<" ";
        }
    }else{
        if(k==1){
            cout<<"NO";
        }else {
            //k>=2
            if(n%2==0){
                cout<<"YES\n";
                cout<<n/2<<endl;
                for(int i = 1 ; i<=n/2 ; i++){
                    cout<<2<<" ";
                }
            }else{
                if(k>=3){
                    cout<<"YES\n";
                    cout<<n/2<<endl;
                    for(int i = 1 ; i<=n/2-1 ; i++){
                        cout<<2<<" ";
                    }
                    cout<<3;
                }else{
                    cout<<"NO";
                }
            }
        }
    }
    cout<<endl;    
}

/*
Case i : If x != 1 , 1*n = n
Case ii : If x == 1 
            -if k == 1 ,No
            -if n== even , 2,2,...n/2 
            -if n == odd && k>=3 Yes 2,2,....(n/2-1) + 3
            -else No
*/

int32_t main()
{
 
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
 cin.tie(NULL);
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
        
    }
    return 0;
}

    