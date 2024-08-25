#include<iostream>
#include<vector>
using namespace std;

bool check(vector<int> nums){
    int n = nums.size()-1;
    int count =0;
    for(int i=0;i<n;i++){
        if(nums[i]>nums[i+1])
            count++;
    }
    if(nums[0]<nums[n])
        count++;

    return count<=1; //when all element same ,count = 0
}

int main () 
{
    vector<int> a = { 1,2,4,5,6,7,8};
    vector<int> b = {5,6,7,8,1,2,4};
    vector<int> c = {1,1,1,1,1,1,1};
    vector<int> d = { 5,6,8,1,4,2};
    cout<<"a is : "<<check(a)<<endl; //Sorted
    cout<<"b is : "<<check(b)<<endl; //Rotated Array
    cout<<"c is : "<<check(c)<<endl; //All element are equal
    cout<<"d is : "<<check(d)<<endl; //Neither rotated nor sorted
    return 0;
}