#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//Brute force approach
void zeroSum(vector<int> arr , int n ){
    int count = 0 ;
    for(int i = 0 ; i<n; i++){
        int sum = 0 ;   
        for(int j = i ; j<n; j++){
            sum += arr[j];
            if(sum == 0){
                count++;
            }
        }
    }
   cout << "Using brute force: " << count << endl;
}
//Time : O(n^2)

//Optimised approach(Prefix Sum)
void zeroSumOpti(vector<int> arr ,int n){
    int ans = 0;

    unordered_map<int, int> mp;
    mp[0]=1;
    int prefixSum = 0;

    for(int i =0 ;i<n;i++){
        prefixSum +=arr[i];

        if(mp.count(prefixSum)){
            ans+= mp[prefixSum]; 
            mp[prefixSum]++;
        }else{
            mp[prefixSum]=1;
        }
    }
    cout<<"Using prefix Sum : "<<ans<<endl;
}

int main () 
{   
    vector<int> arr;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    zeroSum(arr,n);
    zeroSumOpti(arr , n);


    return 0;
}