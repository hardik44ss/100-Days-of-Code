#include<iostream>
#include<vector>
using namespace std;

void BubbleSort(vector<int> arr){
    int n = arr.size();
    bool isSorted=true;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                isSorted=false;
            }
        }
        if(isSorted)
            break;
    }
    for (int i =0 ;i<n ; i++){
        cout<<arr[i]<<" ";
    }
}

int main () 
{
     vector<int> arr = {5,6,7,8,9,1,3,4};
     BubbleSort(arr);
    return 0;
}