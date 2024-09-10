#include<iostream>
using namespace std;

//Binary search
int binarySearch(int arr[], int l, int r, int x){
    if(r>=l){
        int mid = l + (r-l)/2; //Space complexity : O(1)
        if(arr[mid]==x){
            return mid;
        }
        if(arr[mid]>x){
            return binarySearch(arr, l, mid-1, x);
        }
        return binarySearch(arr, mid+1, r, x);
    }
    return -1;
}

int main () 
{
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 10;
    int result = binarySearch(arr, 0, n-1, x);
    (result == -1)? cout<<"Element is not present in array"
                  : cout<<"Element is present at index "<<result;

    return 0;
}
/*
    Space = o(1) + O(1) .......O(1) 
    Total terms : log(n) terms
    Space complexity : O(log(n))
*/