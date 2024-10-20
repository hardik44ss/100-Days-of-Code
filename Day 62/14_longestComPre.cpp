#include <iostream>
#include <vector>
#include <string>
#include <algorithm>  // For sort function

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // If the input list is empty, return an empty string
        if (strs.empty()) return "";
        
        // Sort the list of strings lexicographically
        sort(strs.begin(), strs.end());
        
        // Get the first and the last string after sorting
        string str1 = strs[0];
        string str2 = strs[strs.size() - 1];
        string ans = "";
        
        // Compare the characters of the first and last string
        for (int i = 0; i < str1.size(); i++) {
            if (str1[i] == str2[i]) {
                ans += str1[i];  // Add matching characters to the result
            } else {
                break;  // Stop if there is a mismatch
            }
        }
        
        return ans;  // Return the longest common prefix
    }
};

int main() {
    Solution sol;
    vector<string> strs = {"flower", "flow", "flight"};
    
    string result = sol.longestCommonPrefix(strs);
    
    cout << "Longest Common Prefix: " << result << endl;

    return 0;
}
