#include <iostream>
using namespace std;
 
 
void work(){
    int n,k;
    cin >> n >> k;
 
    cout << (((n+1)*n/2 - (n-k)*(n-k+1)/2)%2?"NO":"YES") << '\n';
}
 
int main(){
 
    int t;
    cin >> t;
    while (t--) work();
    return 0;
}
/*
5
1 1
2 1
2 2
3 2
4 4

*/