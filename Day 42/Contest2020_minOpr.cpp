#include <bits/stdc++.h>
using namespace std;

int solve() {
    int n, k;
    cin >> n >> k;
    int count = 0;
    
    if (k == 1) {
        return n;
    }
    
    // while (n != 0) {
    //     int i = 1;
    //     // Find the largest power of k that is less than or equal to n
    //     for (i = 1; i <= n; i *= k);
    //     count++;
    //     n = n - i / k; // Subtract the largest power of k
    // }
    while(n>0){
        count+= n%k;
        n/=k;
    }

    return count;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cout << solve() << endl;
    }
    return 0;
}
