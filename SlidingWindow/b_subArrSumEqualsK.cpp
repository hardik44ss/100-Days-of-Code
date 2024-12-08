#include<bits/stdc++.h>
using namespace std;

void subArraySumEqualsK(vector<int> arr , int n , int k){
    int ans = 0;

    unordered_map<int, int> mp;
    mp[0]=1;
    int prefixSum = 0;

    for(int i =0 ;i<n;i++){
        prefixSum +=arr[i];

        if(mp.count(prefixSum-k)){
            ans+= mp[prefixSum-k]; 
           
        }
        //ALways update the prefix sum after checking the condition
        mp[prefixSum]++;
    }
    cout<<"Using prefix Sum : "<<ans<<endl;
}

int main () 
{
    vector<int> arr = {2 ,1 ,7 ,3 ,2 ,1 ,4};
    int n = arr.size();
    int k = 7;
    subArraySumEqualsK(arr,n,k);

    return 0;
}