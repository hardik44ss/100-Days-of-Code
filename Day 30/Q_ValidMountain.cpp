class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        // Two pointer approach
        int i = 0;
        int j = arr.size() - 1;
        
        // Traverse while the array is increasing from the left
        while (i < j) {
            if (arr[i] < arr[i + 1]) {
                i++;
            } else if (arr[j - 1] > arr[j]) {
                j--;
            } else {
                return false; // Not strictly increasing or decreasing
            }
        }
        
        // Check if we have a valid mountain shape
        if (i != 0 && j != arr.size() - 1) {
            return true;
        }
        
        return false;
    }
};
