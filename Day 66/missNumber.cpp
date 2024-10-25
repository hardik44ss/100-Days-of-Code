#include <iostream>
#include <vector>

int missingNumber(std::vector<int>& nums) {
    int n = nums.size();
    
    long actual = (n * (n + 1) / 2);
    long sum = 0;
    for (int element : nums) {
        sum += element;
    }

    return (int)(actual - sum);
}

int main() {
    std::vector<int> nums = {3, 0, 1}; // Example input
    std::cout << "Missing number is: " << missingNumber(nums) << std::endl;
    return 0;
}