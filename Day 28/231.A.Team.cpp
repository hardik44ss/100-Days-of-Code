#include<iostream>
#include<vector>
using namespace std;

int countSol(vector<vector<int>> v){
    int size = v.size();
    int count=0;
    for(int i = 0 ;i<size;i++){
        int ones = 0;
        for(int j=0;j<3;j++){
            if(v[i][j]==1){
                ones++;
            }
        }
        if(ones>1){
            count++;
        }
    }
    return count;
}

int main () 
{       
    int n ;
    cin>>n;
    vector<vector<int>> v;
    while(n--){
        vector<int> temp;
        for(int i = 0; i < 3; i++){
            int x;
            cin>>x;
            temp.push_back(x);
        }
        v.push_back(temp);
    }
    cout<<countSol(v);

    return 0;
}