/*
Problem Statement:
Given an n x n matrix of integers, return the maximum sum of any matrix obtained after flipping any number of rows and columns.

Example:
Input: matrix = [[1,-1],[-1,1]]
Output: 4
Explanation: Flipping both rows and columns results in a matrix with all positive values.

Input: matrix = [[1,2,3],[-1,-2,-3],[1,2,3]]
Output: 16
Explanation: Flipping the second row results in a matrix with all positive values.

Constraints:
- n == matrix.length == matrix[i].length
- 1 <= n <= 250
- -10^5 <= matrix[i][j] <= 10^5
*/

#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int neg = 0;
        long long minVal = LLONG_MAX;
        long long sum = 0;

        for (const auto& vec : matrix) {
            for (const auto& val : vec) {
                if (val < 0) {
                    neg++;
                }
                sum += abs(val);
                minVal = min(minVal, (long long)abs(val));
            }
        }

        if (neg % 2 == 1) {
            sum -= 2LL * minVal;
        }

        return sum;
    }
};

int main() {
    // Predefined input matrix
    vector<vector<int>> matrix = {
        {1, -1},
        {-1, 1}
    };

    Solution sol;
    long long result = sol.maxMatrixSum(matrix);

    // Output the result
    cout << "Maximum matrix sum after flipping: " << result << endl;

    return 0;
}

/*
Expected Output:
Maximum matrix sum after flipping: 4
*/