#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;  // Number of test cases

    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        // Calculate square root of n
        int r = sqrt(n);

        // Check if n is a perfect square
        if (r * r == n) {
            cout << "Yes" << endl;  // It can be a square matrix
        } else {
            cout << "No" << endl;   // It cannot be a square matrix
        }
    }

    return 0;
}
