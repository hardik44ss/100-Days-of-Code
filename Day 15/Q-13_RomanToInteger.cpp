class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}};
        
        int total = 0;
        int n = s.length();

        for (int i = 0; i < n; ++i) {
            // If the current numeral is less than the next numeral, subtract
            // it.
            if (i < n - 1 && roman[s[i]] < roman[s[i + 1]]) {
                total -= roman[s[i]];
            } else {
                // Otherwise, add it.
                total += roman[s[i]];
            }
        }

        return total;
    }
};