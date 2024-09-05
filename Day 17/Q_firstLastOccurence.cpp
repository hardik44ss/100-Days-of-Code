class Solution {
public:
    int first_occurance(vector<int> arr, int size, int key) {
        int start = 0;
        int end = size - 1;
        int ans = -1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] == key) {
                ans = mid;
                end = mid - 1;
            } else if (arr[mid] > key) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }

    int last_occurance(vector<int> arr, int size, int key) {
        int start = 0;
        int end = size - 1;
        int ans = -1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] == key) {
                ans = mid;
                start = mid + 1;
            } else if (arr[mid] > key) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {first_occurance(nums, nums.size(), target),
                           last_occurance(nums, nums.size(), target)};

        return ans;
    }
};