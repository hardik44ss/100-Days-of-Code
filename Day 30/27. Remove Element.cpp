#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// int removeElement(vector<int>& nums, int val) {
//     int i = 0;
//     for(int j = 0; j<nums.size(); j++){
//         if(nums[j] != val){
//             nums[i] = nums[j];
//             i++;
//         }
//     }
//     return i;
// }

//Two pointer method
int removeElement(vector<int>& nums, int val) {
    int i=0 ;
    int j=nums.size()-1;
    while(i<=j){
        if(nums[j]==val){
            j--;
        }
        else if(nums[i]==val){
            swap(nums[i],nums[j]);
            i++;
            j--;
        }
        else{
            i++;
        }

    }
    return i;
}

int main () 
{
    vector<int> nums = {0,1,2,2,3,0,4,2};
    int val = 3;
    cout<<removeElement(nums,val)<<endl;
    for(int i = 0; i<nums.size(); i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}