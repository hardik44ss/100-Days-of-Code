#include<iostream>
#include<vector>
using namespace std;

void countSort(vector<int> & vec ){
    vector<int> count(10,0);
    vector<int> output(vec.size(),0);
    for(int i=0;i<vec.size();i++){
        count[vec[i]]++;
    }
   int index=0;
    for(int i=0;i<count.size();i++){
        while(count[i]>0){
            vec[index++]=i;
            count[i]--;
        }
    }
    
}

int main () 
{
    vector<int> vec = {4,2,2,8,3,3,1};
    countSort(vec);
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }
    return 0;
}