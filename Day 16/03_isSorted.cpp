#include<iostream>
#include<vector>
using namespace std;

bool isSorted(int arr[] , int size ){
    if(size==0 || size==1){
        return true;
    }
    if(arr[0]>arr[1])
        return 0;
    else{
        bool ans = isSorted(arr+1,size-1);
        return ans;
    }
}

int main () 
{
    int arr[5]={1,2,4,5,5};
    cout<<"Is SOrted : " <<isSorted(arr,5)<<endl;
    int arr2[5]={1,2,4,5,2};
    cout<<"Is SOrted : " <<isSorted(arr2,5);

    return 0;
}