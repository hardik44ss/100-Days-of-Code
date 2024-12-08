#include<bits/stdc++.h>
using namespace std;

void subarrDivisibleByK(vector<int> arr ,int n ,int k){
    int ans = 0;
    unordered_map<int, int> mp;
    mp[0]=1;
    int prefixSum = 0;

    for(int i =0 ; i<n ; i++){
        prefixSum += arr[i];
        int rem = prefixSum%k;

        if(rem<0){ //if remainder is negative then add k to it
            rem+=k;
        }
        if(mp.count(rem)){
            ans+= mp[rem];
        }
        mp[rem]++;
    }
    cout<<"Using prefix Sum : "<<ans<<endl;
}

void prodLessthanK(vector<int> arr ,int n ,int k){
    int ans = 0;
    int prefixProd = 1;
    int j = 0;
    for(int i = 0 ; i<n ; i++){
        prefixProd *= arr[i];
        while(j<n && prefixProd >= k){
            prefixProd /= arr[j];
            j++;
        }
        ans += i-j+1;
    }
    cout<<"Using Sliding Window : "<<ans<<endl;
}

int main () 
{

    return 0;
}