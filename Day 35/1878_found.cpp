#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n,k;
        cin >> n>>k;
        vector<long long> a(n);
        bool found = false;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if(a[i] == k) found = true;
        }
        if(found){
            cout<<"YES"<<endl;
        }else {
            cout<<"NO"<<endl;
        }
        
    }
    
    return 0;
}
