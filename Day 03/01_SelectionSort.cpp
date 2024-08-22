#include<iostream>
#include<vector>
using namespace std;

void selSort(vector<int> arr ){
    int n = arr.size();
    for (int i=0;i<n-1;i++){
        int m = i; //Min Index
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[m]){
                m=j;
            }
        }
        swap(arr[i],arr[m]);
    }
    for (int i =0 ;i<n ; i++){
        cout<<arr[i]<<" ";
    }
}

int main () 
{
    vector<int> arr = {5,6,7,8,9,1,3,4};
    selSort(arr);
    return 0;
}
//75. Sort Colors