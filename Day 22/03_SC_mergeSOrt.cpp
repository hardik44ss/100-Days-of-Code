#include<iostream>
#include<vector>
using namespace std;


void merge(vector<int> &arr, int s, int mid, int e){
    //Create temporary arrays to store the two parts
    vector<int> leftArr(mid - s + 1);
    vector<int> rightArr(e - mid);
    int n1 = mid - s + 1;
    int n2 = e - mid;

    //Copy data to temporary arrays
    for(int i = 0; i < n1; i++){
        leftArr[i] = arr[s + i];
    }
    for(int i = 0; i < n2; i++){
        rightArr[i] = arr[mid + 1 + i];
    }

    //Merge the two temporary arrays back into the original array
    int i = 0, j = 0, k = s;
    while(i < n1 && j < n2){
        if(leftArr[i] <= rightArr[j]){
            arr[k] = leftArr[i];
            i++;
        }
        else{
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    //Copy the remaining elements of leftArr, if any
    while(i < n1){
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    //Copy the remaining elements of rightArr, if any
    while(j < n2){
        arr[k] = rightArr[j];
        j++;
        k++;
    }
    // delete []leftArr; -used for array
    // delete []rightArr;
}
//Space : O(1) + O(2) + O(4).........O(n)
//Maximum Space : O(n)

void mergeSort(vector<int> &arr, int s, int e){
    //Base condition
    if(s>=e){
        return;
    }
    //Divide the array into two parts
    int mid = s + (e-s)/2;
    //Recursively sort the two parts
    mergeSort(arr, s, mid);
    mergeSort(arr, mid+1, e);
    //Calling the merge funciton
    merge(arr, s, mid, e);
}
//Space : O(log(n))

int main () 
{
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    int n = arr.size();
    mergeSort(arr, 0, n-1);
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
/*
    Space = O(n) + O(log(n)) .......O(n)
    Total terms : log(n) terms
    Space complexity : O(n) + O(log(n)) 
    Space complexity : O(n)

*/