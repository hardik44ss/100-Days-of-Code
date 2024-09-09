#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSubArraySum(const vector<int>& nums) {
    if (nums.empty()) {
        return 0; // Edge case: empty array
    }

    int maxSum = nums[0];
    int currentSum = nums[0];

    for (size_t i = 1; i < nums.size(); ++i) {
        currentSum = max(nums[i], currentSum + nums[i]);
        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}

int main() {
    vector<int> nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> nums2 = {1};
    vector<int> nums3 = {5, 4, -1, 7, 8};

    cout << "Example 1: " << maxSubArraySum(nums1) << endl; // Output: 6
    cout << "Example 2: " << maxSubArraySum(nums2) << endl; // Output: 1
    cout << "Example 3: " << maxSubArraySum(nums3) << endl; // Output: 23

    return 0;
}
