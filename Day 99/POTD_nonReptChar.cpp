/*
Problem Statement:
Given a string, find the first non-repeating character in it and return it. If there is no such character, return '$'.

Example:
Input: s = "geeksforgeeks"
Output: 'f'
Explanation: 'f' is the first non-repeating character in the string.

Input: s = "hello"
Output: 'h'
Explanation: 'h' is the first non-repeating character in the string.

Input: s = "aabb"
Output: '$'
Explanation: There is no non-repeating character in the string.

Constraints:
- 1 <= s.length <= 10^5
- The string contains only lowercase English letters.
*/

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

char nonRepeatingChar(string &s) {
    unordered_map<char, int> map;
    
    // Count frequency of each character in the string
    for (char ch : s) {
        map[ch]++;
    }
    
    // Find the first non-repeating character
    for (char ch : s) {
        if (map[ch] == 1) {
            return ch;
        }
    }
    
    // If no non-repeating character is found, return '$'
    return '$';
}

int main() {
    // Predefined input string
    string s = "geeksforgeeks";

    // Find the first non-repeating character
    char result = nonRepeatingChar(s);

    // Output the result
    cout << "The first non-repeating character is: " << result << endl;

    return 0;
}

/*
Expected Output:
The first non-repeating character is: f
*/