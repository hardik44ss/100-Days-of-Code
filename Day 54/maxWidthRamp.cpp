#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        ios_base::sync_with_stdio(false);  // Optimizing input/output operations
        cin.tie(NULL);  // Unbinding cin from cout for faster input operations
        
        int n = nums.size();
        stack<int> st;  // Stack to store indices
        
        st.push(0);  // Push the index of the first element onto the stack
        
        // Build the stack in decreasing order of nums elements
        for (int i = 1; i < n; i++) {
            if (nums[st.top()] > nums[i]) {
                st.push(i);
            }
        }

        int ans = 0;

        // Traverse the array from right to left to find the maximum width ramp
        for (int i = n - 1; i >= 0; ) {
            // Pop elements from the stack until we find an element smaller than or equal to nums[i]
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                ans = max(ans, i - st.top());  // Calculate potential ramp width
                st.pop();
            }

            if (st.empty()) break;  // If stack is empty, break out of the loop

            i--;  // Move to the next element to the left
        }

        return ans;  // Return the maximum width of the ramp found
    }
};

/*
Explanation:

- A ramp in an integer array nums is a pair (i, j) for which i < j and nums[i] <= nums[j]. The width of such a ramp is j - i.
- The function maxWidthRamp aims to find the maximum width of such a ramp in the given array nums.
- To achieve this, we use a stack to keep track of indices in decreasing order of nums values.
- First, we iterate through the array to populate the stack with indices where nums values are in decreasing order.
- Next, we iterate from right to left through the array:
  - For each element nums[i], we pop elements from the stack until we find an element with a value less than or equal to nums[i].
  - For each popped element, we calculate the potential ramp width (i - popped_index) and update ans if this width is greater than the current ans.
- Finally, the function returns ans, which holds the maximum width of the ramp found.

*/

int main() {
    Solution sol;
    vector<int> nums = {6, 0, 8, 2, 1, 5};
    cout << "Maximum Width of Ramp: " << sol.maxWidthRamp(nums) << endl;
    return 0;
}
