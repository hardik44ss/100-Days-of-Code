#include<iostream>
#include<vector>
using namespace std;

//Two pointer approch

vector<int> merge2Sort(vector<int> arr1 , vector<int> arr2){
    vector<int> result;
    int i = 0 , j = 0 ;
    while(i<arr1.size() && j<arr2.size()){
        if(arr1[i]<arr2[j]){
            result.push_back(arr1[i++]);
        }else{
            result.push_back(arr2[j++]);
        }
    }
    while(i<arr1.size()){
        result.push_back(arr1[i++]);
    }
    while(j<arr2.size()){
        result.push_back(arr1[j++]);
    }
    return result;
}

int main () 
{
    vector<int> a = { 1,4,5,7,9};
    vector<int> b = { 2,3,6,8};
    for ( int i : merge2Sort(a,b)){
        cout<<i<<' ';
    }

    return 0;
}