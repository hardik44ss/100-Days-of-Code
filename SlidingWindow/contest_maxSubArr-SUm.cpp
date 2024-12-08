#include <unordered_map>
#include <vector>
#include <climits>
#include <iostream>

using namespace std;

class Solution {
public:
    /**
     * Finds the maximum subarray sum such that the subarray sum is divisible by k.
     * 
     * @param nums Vector of integers representing the input array.
     * @param k The divisor.
     * @return The maximum subarray sum divisible by k. If no such subarray exists, returns 0.
     */
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size(); // Get the size of the input array
        
        // Create a prefix sums array of size n+1 initialized to 0
        vector<long long> prefixSums(n + 1, 0);

        // Compute the prefix sums
        for (int i = 0; i < n; i++) {
            prefixSums[i + 1] = prefixSums[i] + nums[i]; // Cumulative sum up to index i
        }

        // Map to store the smallest prefix sum for each remainder when divided by k
        unordered_map<int, long long> remainderMap;

        // Initialize the maximum sum to the smallest possible value
        long long maxSum = LLONG_MIN;

        // Iterate through the prefix sums array
        for (int i = 0; i <= n; i++) {
            // Compute the remainder of the current prefix sum modulo k
            int remainder = prefixSums[i] % k;

            // Adjust remainder to be positive
            if (remainder < 0) remainder += k;

            // If the remainder has been seen before, calculate the possible subarray sum
            if (remainderMap.find(remainder) != remainderMap.end()) {
                maxSum = max(maxSum, prefixSums[i] - remainderMap[remainder]); 
                // Update maxSum with the maximum subarray sum found so far
            }

            // If the remainder has not been seen before, store the current prefix sum
            if (remainderMap.find(remainder) == remainderMap.end()) {
                remainderMap[remainder] = prefixSums[i];
            }
        }

        // If maxSum is still LLONG_MIN, it means no valid subarray was found
        return maxSum == LLONG_MIN ? 0 : maxSum;
    }
};

int main() {
    // Predefined input array and divisor
    vector<int> nums = {3, -2, 5, 1};
    int k = 3;

    Solution sol;
    long long result = sol.maxSubarraySum(nums, k);

    // Output the result
    cout << "The maximum subarray sum divisible by " << k << " is: " << result << endl;

    return 0;
}

/*
Expected Output:
The maximum subarray sum divisible by 3 is: 6
*/
