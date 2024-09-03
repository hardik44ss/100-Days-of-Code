#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

void rotateMatrix(vector<vector<int>> &vec){
    int n = vec.size();
    
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            swap(vec[i][j],vec[j][i]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n/2;j++){
            swap(vec[i][j],vec[i][n-j-1]);
        }
    }
    
}

int main () 
{
    vector<vector<int>>  v = {{1,2,3},{4,5,6},{7,8,9} };
    rotateMatrix(v);
    return 0;
}