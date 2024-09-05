#include<iostream>
#include<vector>
using namespace std;

void merge(int *arr, int s , int e){
    int mid = s + (e-s)/2;

    int len1 = mid-s+1;
    int len2 = e-mid;

    int *arr1 = new int[len1]; //Dynamic memory
    int *arr2 = new int[len2]; //We Should delete memory memory

    int putIndex=s;
    for(int i =0 ; i<len1 ; i++){
        arr1[i] = arr[putIndex++];
    }

    int put=mid+1;
    for(int i =0 ; i<len2 ; i++){
        arr2[i] = arr[put++];
    }

    int i=0,j=0;
    int k = s; //For main array index
    while(i<len1 && j<len2){
        if(arr1[i]<arr2[j]){
            arr[k++]=arr1[i++];
        }else{
            arr[k++] = arr2[j++];
        }
    }
    while(i<len1){
        arr[k++]=arr1[i++];
    }
    while(j<len2){
        arr[k++]=arr2[j++];
    }
    delete []arr1;
    delete []arr2;
}

void mergeSort(int * arr , int s , int e){
    
    //Base Case
    if(s>=e)
        return;
    
    //Processing 
    int mid = (s+e)/2;
    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);

    merge(arr,s,e);
}
// TIme complexity : O(nlogn) in all cases
// Space complexity : O(n)

int main () 
{   
    int arr[10] = {5, 3, 7, 2, 4,6,2,7,5,8};
    mergeSort(arr,0,9);
    for(int i : arr){
        cout<<i<<" ";
    }

    return 0;
}
//Homework : inversion problem
