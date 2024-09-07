class Solution
{
    boolean search(vector<int> nums, int target)
    {
        int start = 0, end = nums.size() - 1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            // If the target is found at mid, return true
            if (nums[mid] == target)
            {
                return true;
            }

            // We dont know position of target
            if (nums[start] == nums[mid] && nums[mid] == nums[end])
            {
                start++;
                end--;
            }
            // Left side is sorted
            else if (nums[start] <= nums[mid])
            {
                // Check in the left sorted part
                if (nums[start] <= target && target < nums[mid])
                {
                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
            }
            // Right side is sorted
            else
            {
                // Check  in the right sorted part
                if (nums[mid] < target && target <= nums[end])
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
        }

        //target is not in array
        return false;
    }
}
