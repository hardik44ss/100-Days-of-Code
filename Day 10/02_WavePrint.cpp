#include<iostream>
#include<vector>
using namespace std;


vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    //Write your code here
    vector<int> res;
    //For odd COlumn bottom to top
    //For even ROw top to bottom
    for(int j=0;j<mCols;j++){
        if(j%2==0){
            for(int i=0;i<nRows;i++){
                res.push_back(arr[i][j]);
            }
        }else{
            for(int i=nRows-1;i>=0;i--){
                res.push_back(arr[i][j]);
            }
        }
    }
    return res;
}//Time : O(m*n)

int main () 
{
    
    return 0;
}