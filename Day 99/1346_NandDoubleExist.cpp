/*
Problem Statement:
Given an array arr of integers, check if there exist two indices i and j such that:
- i != j
- 0 <= i, j < arr.length
- arr[i] == 2 * arr[j]

Example:
Input: arr = [10, 2, 5, 3]
Output: true
Explanation: For i = 0 and j = 1, arr[0] == 2 * arr[1].

Input: arr = [7, 1, 14, 11]
Output: true
Explanation: For i = 2 and j = 0, arr[2] == 2 * arr[0].

Input: arr = [3, 1, 7, 11]
Output: false
Explanation: There is no i and j that satisfy the conditions.

Constraints:
- 2 <= arr.length <= 500
- -10^3 <= arr[i] <= 10^3
*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> seen;
        for (int num : arr) {
            if (seen.count(2 * num) || (num % 2 == 0 && seen.count(num / 2))) {
                return true;
            }
            seen.insert(num);
        }
        return false;
    }
};

int main() {
    // Predefined input array
    vector<int> arr = {10, 2, 5, 3};

    Solution sol;
    bool result = sol.checkIfExist(arr);

    // Output the result
    cout << "Does the array contain elements such that one is double the other? " << (result ? "Yes" : "No") << endl;

    return 0;
}

/*
Expected Output:
Does the array contain elements such that one is double the other? Yes
*/
