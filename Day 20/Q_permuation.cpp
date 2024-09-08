class Solution {
public:

    void permuatation(vector<vector<int>> &ans , vector<int> nums , int index){
        //Base case 
        if(index >= nums.size()){
            ans.push_back(nums);
            return ;
        }
        //Processing 
        for(int i=index;i<nums.size();i++){
            swap(nums[index],nums[i]);
            permuatation(ans , nums , index+1);
            swap(nums[index],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans ; 
        int index = 0 ;
        permuatation(ans , nums , index);
        return ans;
        
    }
};