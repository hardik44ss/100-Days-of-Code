#include<iostream>
using namespace std;

//Binary search
int binarySearch(int arr[], int l, int r, int x){
    if(r>=l){
        int mid = l + (r-l)/2;
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
    Recurance relation: 
        T(n) = T(n/2) + T(Base condition)
        T(Base condition )= O(1)

        T(n)   = T(n/2) + O(1)
        T(n/2) = T(n/4) + O(1)
        T(n/4) = T(n/8) + O(1)
        .
        .
        .
        T(1)   = O(1)
    Sum  -----------------------
        T(n) = O(1) {terms in the series are in the form of 1/2^k}
        terms = total no. in (1 + 1/2 + 1/4 + 1/8 + ... + 1/2^k)
        
        At the end : 
            Condition : 1/2^k < n
            1/2^k = n
            k = log(n)
        terms = O(log(n))
                
        T(n) = O(log(n))
        Space complexity : O(log(n))

*/