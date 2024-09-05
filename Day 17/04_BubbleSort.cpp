#include<iostream>
#include<vector>
using namespace std;

//Bubble sort using recursion 

vector<int> bubbleSort(vector<int> & ans , int n ){
    if(n==0  || n==1){
        return ans;
    }
    for(int j=0;j<n;j++){
        if(ans[j]>ans[j+1]){
            swap(ans[j],ans[j+1]);
        }
    }
    return bubbleSort(ans,n-1);
}

int main () 
{
    vector<int> vec = {4,2,3,6,2,4,6,3};
    vector<int> ans = bubbleSort(vec, vec.size()-1);
    for(int i : ans){
        cout<<i<<" ";
    }
    return 0;
}