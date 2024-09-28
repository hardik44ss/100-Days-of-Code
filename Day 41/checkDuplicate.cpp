#include <iostream>
#include <vector>
#include <map>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::map<int, int> check; // Correctly initialize map with int key and int value
        for(unsigned int i = 0; i < nums.size(); ++i) {
            check[nums[i]]++;
            if(check[nums[i]] == 2) return true;
        }
        return false;
    }
};

int main(){
    Solution s;
    std::vector<int> nums = {1, 2, 3, 1};
    std::cout << std::boolalpha << s.containsDuplicate(nums) << std::endl;

    return 0;
}