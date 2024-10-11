#include <vector>
#include <queue>
#include <functional>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Min-heap to store the k largest elements
        priority_queue<int, vector<int>, greater<int>> pq;

        // Iterate through all elements in the array
        for(const int& num : nums) {
            pq.push(num);
            // If the size of the heap exceeds k, remove the smallest element
            if(pq.size() > k) {
                pq.pop();
            }
        }

        // The top element of the heap is the k-th largest element
        return pq.top();
    }
};
#include <iostream>

int main() {
    Solution sol;
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    cout << "The " << k << "th largest element is " << sol.findKthLargest(nums, k) << endl;
    return 0;
}