#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkEqual(int count1[26], int count2[26]) {
        for (int i = 0; i < 26; i++) {
            if (count1[i] != count2[i]) {
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();

        // If s1 is longer than s2, s1 can't be a permutation of any substring of s2
        if (n1 > n2) {
            return false;
        }

        int count1[26] = {0}; // Frequency array for s1
        int count2[26] = {0}; // Frequency array for the current window in s2

        // Fill the frequency array for s1
        for (int i = 0; i < n1; i++) {
            count1[s1[i] - 'a']++;
            count2[s2[i] - 'a']++;
        }

        // Check the first window
        if (checkEqual(count1, count2)) {
            return true;
        }

        // Sliding window to check the rest of the string
        for (int j = n1; j < n2; j++) {
            // Add the new character to the current window
            count2[s2[j] - 'a']++;

            // Remove the old character from the current window
            count2[s2[j - n1] - 'a']--;

            // Check if the current window matches s1
            if (checkEqual(count1, count2)) {
                return true;
            }
        }

        return false;
    }
};

// Driver code
int main() {
    Solution obj;
    string s1 = "ab";
    string s2 = "eidboaooo";
    cout << obj.checkInclusion(s1, s2) << endl; // Output should be true (1)
    return 0;
}
