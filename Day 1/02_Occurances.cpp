#include<iostream>
using namespace std;

//In an sorted array a unique element is occured many time so find index of first index and last index ,also find total occurances
int first_occurance(int arr[] , int size,int key){
    int start = 0;
    int end = size-1;
    int ans = -1;
    while(start <= end){
        int mid = start + (end-start)/2;
        if(arr[mid] == key){
           ans=mid;
           end = mid-1;
        }
        else if(arr[mid] > key){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return ans;
}

int last_occurance(int arr[] , int size,int key){
    int start = 0;
    int end = size-1;
    int ans = -1;
    while(start <= end){
        int mid = start + (end-start)/2;
        if(arr[mid] == key){
           ans=mid;
           start = mid+1;
        }
        else if(arr[mid] > key){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return ans;
}

int main () 
{
    int pvt[10]={1,2,3,5,6,8,8,8,8,8};
    cout<<"Firstt occ : "<<first_occurance(pvt,10,8)<<endl;
    cout<<"Last occ : "<<last_occurance(pvt,10,8)<<endl;
    //Total occurance 
    cout<<"Total occurance : "<<last_occurance(pvt,10,8)-first_occurance(pvt,10,8)+1<<endl;
    return 0;
}