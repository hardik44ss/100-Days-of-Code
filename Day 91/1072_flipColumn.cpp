/*
Problem Statement:
Given a binary matrix mat, you can choose any number of columns in the matrix and flip every cell in that column (i.e., change the value of the cell from 0 to 1 or from 1 to 0).

Return the maximum number of rows that have all values equal after some number of flips.

Example:
Input: mat = [[0,1],[1,1]]
Output: 1
Explanation: After flipping no values, 1 row has all values equal.

Input: mat = [[0,1],[1,0]]
Output: 2
Explanation: After flipping the first column, both rows have all values equal.

Input: mat = [[0,0,0],[0,0,1],[1,1,0]]
Output: 2
Explanation: After flipping the second and third columns, the first and second rows have all values equal.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& mat) {
        unordered_map<string, int> patFreq;
        
        for (const auto& row : mat) {
            string pattern;
            if (row[0] == 0) {
                for (int bit : row) pattern += to_string(bit);
            } else {
                for (int bit : row) pattern += to_string(bit ^ 1);
            }
            patFreq[pattern]++;
        }
        
        int maxFreq = 0;
        for (const auto& pair : patFreq) {
            maxFreq = max(maxFreq, pair.second);
        }
        return maxFreq;
    }
};

int main() {
    // Predefined input matrix
    vector<vector<int>> mat = {
        {0, 1},
        {1, 1}
    };

    Solution sol;
    int result = sol.maxEqualRowsAfterFlips(mat);

    // Output the result
    cout << "Maximum number of rows with all values equal after flips: " << result << endl;

    return 0;
}

/*
Expected Output:
Maximum number of rows with all values equal after flips: 1
*/