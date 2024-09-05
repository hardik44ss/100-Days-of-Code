
#include<iostream>
#include<vector>
using namespace std;

//Selection sort using Recursion

void selectionSort(vector<int> &vec , int i , int n ){
    if(i == n) return;
    int minIndex = i ;
    for(int j=i+1;j<n;j++){
        if(vec[minIndex] > vec[j]){
            minIndex = j ;
        }
    }
    swap(vec[i],vec[minIndex]);
    selectionSort(vec,i+1,n);
}

int main () 
{
    vector<int> vec = {4,2,3,6,11,2,4,7,6,3};
    selectionSort(vec,0, vec.size());
    for(int i : vec){
        cout<<i<<" ";
    }
    return 0;
}