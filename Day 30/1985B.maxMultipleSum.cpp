#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;

        int maxSum = 0;
        int bestX = 0;

        // Loop through all possible values of x from 2 to n
        for (int x = 2; x <= n; x++) {
            int sum = 0;
            
            // Sum all multiples of x that are <= n
            for (int multiple = x; multiple <= n; multiple += x) {
                sum += multiple;
            }

            // If this x gives a higher sum, update bestX
            if (sum > maxSum) {
                maxSum = sum;
                bestX = x;
            }
        }
        
        // Output the optimal value of x
        cout << bestX << endl;
    }

    return 0;
}
