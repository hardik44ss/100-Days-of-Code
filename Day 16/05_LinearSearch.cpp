#include<iostream>
#include<vector>
using namespace std;

bool linearSearch(int arr[] ,int size , int target){
    if(size==0){
        return 0;
    }
    if(arr[0]==target){
        return 1;
    }
    else{
        bool ans = linearSearch(arr+1,size-1,target);
        return ans;
    }
}


int main () 
{
    int arr[9] = {3,5,23,45,3,345,23,43,23};
    cout<<"Is 45 present in array : "<<linearSearch(arr,9,45)<<endl;
    cout<<"Is 44 present in array : "<<linearSearch(arr,9,44)<<endl;
    return 0;
}