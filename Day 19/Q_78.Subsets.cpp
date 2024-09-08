class Solution {
public:
    void solve(vector<int> nums , vector<vector<int>> &ans ,vector<int> output , int index  ){
        if(index>=nums.size()){
            ans.push_back(output);
            return;
        }

        //Exclude 
        solve(nums,ans,output,index+1);

        //Include
        int element = nums[index];
        output.push_back(element);
        solve(nums,ans,output,index+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;
        solve( nums , ans , output , index );
        return ans;
    }
};
/* ------------JAVA --------------
class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> subset = new ArrayList<>();

        createSubset(nums, 0, res, subset);
        return res;        
    }

    private void createSubset(int[] nums, int index, List<List<Integer>> res, List<Integer> subset) {
        if (index == nums.length) {
            res.add(new ArrayList<>(subset));
            return;
        }

        subset.add(nums[index]);
        createSubset(nums, index + 1, res, subset);

        subset.remove(subset.size() - 1);
        createSubset(nums, index + 1, res, subset);
    }    
}
*/
/* ---------------- string subsequences ---------------------
#include <bits/stdc++.h> 

void solve(string str , int index , string output , vector<string> &ans){
	if(index >= str.length()){
		if(output.length() > 0){
			ans.push_back(output);
		}
		return ; 
	}

	solve(str, index +1 , output , ans);

	char element = str[index];
	output.push_back(element);
	solve(str, index + 1 , output , ans);
}
vector<string> subsequences(string str){
	
	// Write your code here
	vector<string> ans;
	string output = "";
	int index = 0 ;
	solve(str, index , output , ans);
	return ans;
}


*/
//TREE BNAO