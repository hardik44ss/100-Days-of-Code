/*
Problem Statement:
Given two strings, determine if they are anagrams of each other. Two strings are anagrams if they contain the same characters with the same frequencies.

Example:
Input: s1 = "listen", s2 = "silent"
Output: true

Input: s1 = "hello", s2 = "world"
Output: false

Constraints:
- The strings can contain any printable ASCII characters.
- The strings can be of different lengths.
*/

#include <iostream>
#include <map>
#include <string>

using namespace std;

bool isAnagram(string s1, string s2) {
    map<char, int> mp1, mp2;
    
    // Count frequency of each character in s1
    for (auto it : s1) {
        mp1[it]++;
    }
    
    // Count frequency of each character in s2
    for (auto it : s2) {
        mp2[it]++;
    }
    
    // If the sizes of the maps are different, the strings are not anagrams
    if (mp1.size() != mp2.size()) {
        return false;
    }
    
    // Compare the frequency of each character in both maps
    for (auto it : mp1) {
        if (mp2[it.first] != it.second) {
            return false;
        }
    }
    
    return true;
}

int main() {
    // Predefined input strings
    string s1 = "listen";
    string s2 = "silent";

    // Check if the strings are anagrams
    bool result = isAnagram(s1, s2);

    // Output the result
    cout << "Are the strings \"" << s1 << "\" and \"" << s2 << "\" anagrams? " << (result ? "Yes" : "No") << endl;

    return 0;
}

/*
Expected Output:
Are the strings "listen" and "silent" anagrams? Yes
*/