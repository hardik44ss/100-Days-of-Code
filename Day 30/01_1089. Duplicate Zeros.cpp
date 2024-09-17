class Solution {
public:
    
    void insertZero(vector<int> & arr, int index){
        for(int i=arr.size() -2 ; i>index ; i--){
            arr[i+1] = arr[i];
        }
        arr[index+1]=0;
        
    }
    
    void duplicateZeros(vector<int>& arr) {
        // Input: arr = [1,0,2,3,0,4,5,0]
        // Output: [1,0,0,2,3,0,0,4]
        for(int i = 0;i<arr.size()-1;i++){
            if(arr[i] == 0){
                insertZero(arr,i);
                i++;
            }
        }      
        
    }
};