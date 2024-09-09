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
}


//Merge sort time complexity 
//Merge sort function , Start = s , end = e
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
    Merge Sort works as follows:

        Divide: Split the array into two halves. : 2T(n/2)
        Conquer: Recursively sort both halves.
        Combine: Merge the two sorted halves into a single sorted array. : O(n)

    Recurance relation:
        T(n) = 2T(n/2) + O(n)

        T(n)  = 2T(n/2) + O(n)
    2*[T(n/2) = 2T(n/4) + O(n/2)]
    4*[T(n/4) = 2T(n/8) + O(n/4)]
    .
    .
    .
       T(0)   =   O(1)
    Sum  -----------------------
        T(n) = terms*O(n) 
        terms = total no. in (1 + 2 + 4 + 8 + ... + 2^k)
        terms = log(n)
                
        T(n) = O(n) + O(n/2) + O(n/4) + ... + O(1)
        T(n) = terms * O(n)
        terms = log(n)
        T(n) = O(nlog(n))
        Space complexity : O(n)
        for storing elements(n/2 + n/2)  in left and write arrays
        //Merge sort is a stable sort algorithm

*/