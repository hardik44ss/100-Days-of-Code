#include<iostream>
#include<vector>
using namespace std;
 
//We have to convert a sorted array into a rotated array from the element at key 
// Original : 1,2,3,5,6,7,8
// key : 3
// Rotated  : 6,7,8,1,2,3,5

void print(vector<int> temp){
    
    for(int i=0;i<temp.size() ;i++){
        cout<<temp[i]<<" ";
    }
    cout<<endl;
}

void rotate(vector<int> arr , int k){
    cout<<"Original : ";
    print(arr);

    int n = arr.size();
    vector<int> temp(n);
    for(int i=0;i<n;i++){
        temp[(i+k)%n] = arr[i];
    }
    cout<<"Rotated : ";
    print(temp);
}

int main () 
{
    vector<int> v = { 1,2,3,4,5,6,7,9};
    rotate(v, 3);
    return 0;
}