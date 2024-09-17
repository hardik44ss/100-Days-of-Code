//Remove 3rd duplicate element from the array
#include<iostream>
#include<vector>
using namespace std;

int removeDuplicate(vector<int> & nums){
    int n = nums.size();
    if(n <= 2) return n;
    int index = 2;
    for(int i = 2; i < n; i++){
        if(nums[i] != nums[index - 2]){
            nums[index++] = nums[i];
        }
    }
    return index;
    
}

int main () 
{
    vector<int> arr = {1, 1, 1, 2, 2, 3};
    cout << removeDuplicate(arr) << endl;
    for(int i : arr){
        cout << i << " ";
    }
    return 0;
}