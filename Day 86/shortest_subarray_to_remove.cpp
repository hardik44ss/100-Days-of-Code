#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        
        // Step 1: Find the longest non-decreasing prefix
        int left = 0;
        while (left + 1 < n && arr[left] <= arr[left + 1]) {
            left++;
        }
        
        // If the entire array is already sorted
        if (left == n - 1) return 0;
        
        // Step 2: Find the longest non-decreasing suffix
        int right = n - 1;
        while (right > 0 && arr[right - 1] <= arr[right]) {
            right--;
        }
        
        // Step 3: Find the minimum length to remove by comparing prefix and suffix
        int result = min(n - left - 1, right);
        
        // Step 4: Use two pointers to find the smallest middle part to remove
        int i = 0, j = right;
        while (i <= left && j < n) {
            if (arr[i] <= arr[j]) {
                result = min(result, j - i - 1);
                i++;
            } else {
                j++;
            }
        }
        
        return result;
    }
};

int main() {
    // Predefined input array
    vector<int> arr = {1, 2, 3, 10, 4, 2, 3, 5};

    Solution sol;
    int result = sol.findLengthOfShortestSubarray(arr);

    // Output the result
    cout << "The length of the shortest subarray to remove is: " << result << endl;

    return 0;
}

/*
Expected Output:
The length of the shortest subarray to remove is: 3
*/