#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int> &vec , int s , int e ){

    //Place pivot at its postion 

    int pivot = vec[s];
    int cnt = 0;
    for(int i = s+1;i<=e;i++){
        if(vec[i]<=pivot){
            cnt++;
        }
    }
    int pivotIndex = s+cnt;
    swap(vec[s],vec[pivotIndex]);

    // Make array :  (smaller than pivot ) <- pivot <- (greater than pivot)

    int i=s,j=e;
    while(i<pivotIndex && j > pivotIndex){
        
        while(vec[i]<vec[pivotIndex]){
            i++;
        }
        while(vec[j]>vec[pivotIndex]){
            j--;
        }

        if(i<pivotIndex && j > pivotIndex)
        {
            swap(vec[i++],vec[j--]);
        }
    }
    return pivotIndex;    
}

void quickSort(vector<int> &vec , int s , int e ){
    //Base case
    if(s >= e)
        return ;

    //Process : find index of pivot
    int pivot = partition(vec,s , e);

    //Recursive Call
    quickSort(vec , s , pivot - 1);
    quickSort(vec , pivot + 1 , e);
}

int main () 
{
    vector<int> arr = {5, 3, 7, 2, 4,6,2,7,5,8};
    quickSort(arr,0,9);
    for(int i : arr){
        cout<<i<<" ";
    }
    return 0;
}
//Homework: check about stabity , why 