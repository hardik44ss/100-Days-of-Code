#include <iostream>
#include <vector>
#include <limits.h>  // For INT_MAX

using namespace std;

int main() {
    ios::sync_with_stdio(0);  // Fast input/output
    cin.tie(0);               // Unties cin from cout
    cout.tie(0);
    
    int n, k;
    cin >> n >> k;  // Reading number of elements and the window size
    
    vector<int> a(n);  // Vector to store the elements
    for (int i = 0; i < n; i++) {
        cin >> a[i];  // Reading the elements
    }
    
    vector<int> pref(200005);  // Prefix sum array of size 200005
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + a[i];  // Calculating prefix sums
    }
    
    int mini_total = INT_MAX;  // To keep track of the minimum sum
    int index = 0;             // To store the index of the minimum sum window
    
    // Sliding window to find the subarray with the minimum sum
    for (int i = 0; i <= n - k; i++) {
        int total = pref[i + k] - pref[i];  // Sum of the subarray of length k
        if (total < mini_total) {
            mini_total = total;
            index = i + 1;  // Storing the index (1-based index)
        }
    }
    
    cout << index << endl;  // Output the starting index of the subarray with the minimum sum
    
    return 0;
}


// pref = [0, 1, 3, 9, 10, 11, 18, 19]
// Step 2: Calculate the sum of each subarray of length k = 3
// We calculate the sum of subarrays using the prefix sum array:

// Subarray starting at index 0: pref[3] - pref[0] = 9 - 0 = 9 (Subarray: [1, 2, 6])
// Subarray starting at index 1: pref[4] - pref[1] = 10 - 1 = 9 (Subarray: [2, 6, 1])
// Subarray starting at index 2: pref[5] - pref[2] = 11 - 3 = 8 (Subarray: [6, 1, 1]) ← Minimum
// Subarray starting at index 3: pref[6] - pref[3] = 18 - 9 = 9 (Subarray: [1, 1, 7])
// Subarray starting at index 4: pref[7] - pref[4] = 19 - 10 = 9 (Subarray: [1, 7, 1])
// Step 3: Find the minimum sum
// The subarray [6, 1, 1] starting at index 2 (0-based) has the smallest sum, which is 8. Since the problem asks for a 1-based index, the output should be 3 (2 + 1).