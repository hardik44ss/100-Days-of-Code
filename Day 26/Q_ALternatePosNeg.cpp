#include<iostream>
#include<vector>
using namespace std;

void rearrange(vector<int> &arr){
    int n = arr.size();
    vector<int> pos;
    vector<int> neg;
    for(int i=0;i<n;i++){
        if(arr[i]>=0){
            pos.push_back(arr[i]);
        }else{
            neg.push_back(arr[i]);
        }
    }

    int i=0,j=0,k=0;
    while(i<pos.size() && j<neg.size()){
        arr[k++] = pos[i++];
        arr[k++] = neg[j++];
    }
    while(i<pos.size()){
        arr[k++] = pos[i++];
   
    }
    while(j<neg.size()){
      
        arr[k++] = neg[j++];
    }
}

int main () 
{
    vector<int> arr = {4,2,-2,-8,3,-3,1};
    //Before rearranging
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    rearrange(arr);

    //After rearranging
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}