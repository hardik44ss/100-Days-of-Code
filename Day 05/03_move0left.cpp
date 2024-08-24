#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;



vector<int> moveZero(vector<int> arr){
    int nonZero = 0;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] != 0){
            swap(arr[nonZero], arr[i]);
            nonZero++;
        }
    }
    return arr;

}

int main () 
{
    vector<int> v = { 0,1,0,3,12,0};
    vector<int> result = moveZero(v);
    for(int i : result){
        cout<<i<<" ";
    }

    return 0;
}