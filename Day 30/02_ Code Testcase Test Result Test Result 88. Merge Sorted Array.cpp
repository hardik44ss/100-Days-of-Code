class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> v;
        int a = 0, b = 0;

        // Merge elements from nums1 and nums2
        while (a < m && b < n) {
            if (nums1[a] <= nums2[b]) {
                v.push_back(nums1[a++]);
            } else {
                v.push_back(nums2[b++]);
            }
        }

        // Add remaining elements from nums1
        while (a < m) {
            v.push_back(nums1[a++]);
        }

        // Add remaining elements from nums2
        while (b < n) {
            v.push_back(nums2[b++]);
        }

        // Copy the merged elements back to nums1
        for (int i = 0; i < v.size(); i++) {
            nums1[i] = v[i];
        }
    }
};