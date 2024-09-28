#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;  // Input number of test cases
    while (t--) {
        int n;
        cin >> n;  // Input size of the array
        vector<int> x(n);
        for (int i = 0; i < n; ++i) {
            cin >> x[i];  // Input the array elements
        }
        
        // Logic to check the condition
        if (n > 2 || x[0] + 1 == x[n-1]) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
    return 0;
}
