#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{   // @AcceptedCode
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n; cin >> n;
        if (n < 5 ) {cout << "-1" << endl; continue;}
        for (int i = 1 ; i <= n ; i++) {
            if (i == 5) continue;
            if (i & 1) cout << i << " ";
        }
        cout << 5 << " " << 4 << " ";
        for (int i = 2 ; i <= n ; i++) {
            if (i == 4) continue;
            if (i % 2 == 0) cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}