//Man can climb 1 or 2 stairs at a time
#include <bits/stdc++.h> 
using namespace std;
int countDistinctWays(int nStairs) {
    if(nStairs<0)
        return 0;
    //  Write your code here.
    if(nStairs==0)
        return 1;
    int ans = countDistinctWays(nStairs-1)+countDistinctWays(nStairs-2);
    return ans;
}

int main(){
    int n;
    cin>>n;
    cout<<countDistinctWays(n)<<endl;
}