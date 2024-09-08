class Solution {
public:
    void solve(string digits,string output , int index , string Mapping[] , vector<string> &ans){

        //Base case 
        if(index >= digits.length()){
            ans.push_back(output);
            return;
        }
        //Processing 
        int number = digits[index]-'0';
        string value = Mapping[number];
        for(int i=0 ; i<value.length();i++){
            output.push_back(value[i]);
            solve(digits , output , index+1 , Mapping , ans);
            output.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length() == 0){
            return ans;
        }
        string output ; 
        int index = 0 ; 
        string Mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits , output , index , Mapping,ans);
        return ans;
    }
};

//TREE bnao 