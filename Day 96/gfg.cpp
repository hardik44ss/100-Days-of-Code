/*
Problem Statement:
Given an unsorted array of integers, find the smallest missing positive integer.

Example:
Input: arr = [3, 4, -1, 1]
Output: 2
Explanation: The smallest missing positive integer is 2.

Input: arr = [1, 2, 0]
Output: 3
Explanation: The smallest missing positive integer is 3.

Constraints:
- The array can contain both positive and negative integers.
- The array can contain duplicates.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findFirstPositiveIdx(vector<int> arr) {
    int idx = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] >= 0) {
            idx = i;
            return idx;
        }
    }
    return arr.size();
}

int missingNumber(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int refIdx = findFirstPositiveIdx(arr);
    if (refIdx == arr.size()) {
        return 1;
    } else {
        if (arr[refIdx] > 1) {
            return 1;
        }
        for (int i = refIdx + 1; i < arr.size(); i++) {
            if (arr[i - 1] != arr[i] && (arr[i - 1] + 1) != arr[i]) {
                return arr[i - 1] + 1;
            }
        }
    }
    return arr[arr.size() - 1] + 1;
}

int main() {
    // Predefined input array
    vector<int> arr = {3, 4, -1, 1};

    int result = missingNumber(arr);

    // Output the result
    cout << "The smallest missing positive integer is: " << result << endl;

    return 0;
}

/*
Expected Output:
The smallest missing positive integer is: 2
*/