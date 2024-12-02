/*
Problem Statement:
Given a sentence that consists of some words separated by a single space, and a searchWord, check if searchWord is a prefix of any word in the sentence. Return the index of the word (1-based) where searchWord is a prefix. If searchWord is not a prefix of any word, return -1.

Example:
Input: sentence = "i love eating burger", searchWord = "burg"
Output: 4
Explanation: "burg" is a prefix of "burger" which is the 4th word in the sentence.

Input: sentence = "this problem is an easy problem", searchWord = "pro"
Output: 2
Explanation: "pro" is a prefix of "problem" which is the 2nd word in the sentence.

Input: sentence = "i am tired", searchWord = "you"
Output: -1
Explanation: "you" is not a prefix of any word in the sentence.

Constraints:
- 1 <= sentence.length <= 100
- 1 <= searchWord.length <= 10
- sentence consists of lowercase English letters and spaces.
- searchWord consists of lowercase English letters.
*/

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        // Split the sentence into words
        istringstream stream(sentence);
        string word;
        int index = 1; // 1-based index
        
        while (stream >> word) {
            // Check if the word starts with the searchWord
            if (word.find(searchWord) == 0) {
                return index;
            }
            index++;
        }
        
        // Return -1 if no word starts with the searchWord
        return -1;
    }
};

int main() {
    // Predefined input sentence and searchWord
    string sentence = "i love eating burger";
    string searchWord = "burg";

    Solution sol;
    int result = sol.isPrefixOfWord(sentence, searchWord);

    // Output the result
    cout << "The index of the word where \"" << searchWord << "\" is a prefix: " << result << endl;

    return 0;
}

/*
Expected Output:
The index of the word where "burg" is a prefix: 4
*/