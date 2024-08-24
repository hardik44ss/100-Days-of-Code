#include<iostream>
#include<vector>
using namespace std;

//TWO POINTER APPROACH

vector<int> rev_Arr(vector<int> &arr){
    int s=0;
    int e = arr.size()-1;
    while(s<e){
        swap(arr[s],arr[e]);
        s++;
        e--;
    }
    return arr;

}


int main () 
{
    vector<int> v = {1,2,3,6,7,8,9};
    vector<int> v1 = rev_Arr(v);
    cout<<"Reversed array is: ";
    for (int i : v1){
        cout<<i<<" ";
    }
    return 0;
}