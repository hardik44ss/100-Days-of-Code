#include "bits/stdc++.h"
#define int long long
#define uint unsigned long long
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define fr(i,n) for(int i=0; i<(n); i++)

// make sure to sort before applying unique // else only consecutive duplicates would be removed 
#define bin(x,y)  bitset<y>(x) 
using namespace std;
int MOD=1e9+7;      // Hardcoded, directly change from here for functions!



void solve(){
    int n;
    cin>>n ;
    vi v(n-1);
    for(int i=0; i<n-1; i++){
        cin>>v[i];
    }
    int ans = accumulate(v.begin(),v.end(),0);
    
    cout<<-ans<<endl;

    
}

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

    