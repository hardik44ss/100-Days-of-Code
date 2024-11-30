/*
Problem Statement:
Given two binary strings, return their sum (also a binary string).

Example:
Input: s1 = "11", s2 = "1"
Output: "100"

Input: s1 = "1010", s2 = "1011"
Output: "10101"

Constraints:
- Each input string is a non-empty string consisting only of '0' and '1'.
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addBinary(string s1, string s2) {
        // Reverse iterators for both strings
        auto it1 = s1.rbegin();
        auto it2 = s2.rbegin();
        
        // Result string
        string ans(max(s1.size(), s2.size()) + 1, '0');
        auto it3 = ans.begin();
        
        int carry = 0;
        while(it1 != s1.rend() || it2 != s2.rend() || carry) {
            int cur = carry;
            
            // Add digit from s1
            if(it1 != s1.rend()) {
                cur += *it1 - '0';
                it1++;
            }
            
            // Add digit from s2
            if(it2 != s2.rend()) {
                cur += *it2 - '0';
                it2++;
            }
            
            // Calculate current digit and carry
            *it3 = cur % 2 + '0';
            carry = cur / 2;
            it3++;
        }
        
        // Skip leading zeros
        for(size_t i = 0; i < ans.size(); i++) {
            if(ans[i] == '1') {
                return ans.substr(i, ans.size() - i);
            }
        }
        
        // No '1' found, return "0"
        return "0";
    }
};

int main() {
    // Predefined input binary strings
    string s1 = "1010";
    string s2 = "1011";

    Solution sol;
    string result = sol.addBinary(s1, s2);

    // Output the result
    cout << "Sum of binary strings: " << result << endl;

    return 0;
}

/*
Expected Output:
Sum of binary strings: 10101
*/