/*
Problem Statement:
Given a circular array code of length n and an integer k, return the decrypted array to defuse the bomb.

If k == 0, set all elements in the decrypted array to 0.
If k > 0, replace the ith element with the sum of the next k elements.
If k < 0, replace the ith element with the sum of the previous k elements.

The array is circular, so elements beyond the end of the array wrap around to the beginning.

Example:
Input: code = [5,7,1,4], k = 3
Output: [12,10,16,13]

Input: code = [1,2,3,4], k = 0
Output: [0,0,0,0]

Input: code = [2,4,9,3], k = -2
Output: [12,5,6,13]
*/

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n, 0);
        if (k == 0) return ans;
        
        if (k > 0) {
            int wsum = accumulate(code.begin() + 1, code.begin() + k + 1, 0);
            ans[0] = wsum;
            for (int l = 1, r = k + 1; l < n; r++, l++) {
                wsum += -code[l] + code[r % n];
                ans[l] = wsum;
            }
            return ans;
        }
        
        // k < 0
        k = -k;
        int wsum = accumulate(code.end() - k, code.end(), 0);
        ans[0] = wsum;
        for (int r = 0, l = n - k; r < n - 1; r++, l++) {
            wsum += -code[l % n] + code[r];
            ans[r + 1] = wsum;
        }
        return ans;
    }
};

int main() {
    // Predefined input array and k value
    vector<int> code = {5, 7, 1, 4};
    int k = 3;

    Solution sol;
    vector<int> result = sol.decrypt(code, k);

    // Output the result
    cout << "Decrypted array: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

/*
Input : code = [5, 7, 1, 4], k = 3
Expected Output:
Decrypted array: 12 10 16 13
*/