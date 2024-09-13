#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

/*APproch : 
    i. Check if n is perfect square or not
    ii. find no. of '1'
    iii. no. of '1' should be : root*4 - 4 

NOTE : The string is always the result of writing out the strings of a beautiful matrix.
    --It mean the given string is always  a beautiful matrix , so we count no. of 1's other wise the solution is different
*/
int main(){

    int t;
    cin>>t;
 
    while(t--){
        int n;
        string s;
        cin>>n>>s;
    
        int root = sqrt(n);
        if(root*root != n){
            cout<<"No";
        }else{
            int a = std::count(s.begin(), s.end(), '1');
            if(a==root*4 - 4){
                cout<<"Yes";
            }else{
                cout<<"No";
            }
        }
        cout<<"\n";
    }
    return 0;
}
/* -----------  ANOTHER APPROACH
int root=sqrt(n);
        if (root*root != n) {
            cout<< "NO"<<endl;
            continue;
        }
 
        int k=root;
        bool isBeauty=true;
        for (int i = 0;i < k;i++){
            if (s[i]!='1') {
                isBeauty=false;
                break;
            }
 
            if (s[n-k+i]!='1'){
                isBeauty=false;
                break;
            }
 
            if (s[i*k]!='1'){
                isBeauty=false;
                break;
            }
 
            if (s[i*k+k-1]!='1'){
                isBeauty=false;
                break;
            }
        }
 
        if (isBeauty){
            for (int i=1;i<k-1;i++){
                for (int j=1;j<k-1;j++){
                    if (s[i*k+j]!='0'){
                        isBeauty=false;
                        break;
                    }
                }
                if (!isBeauty) break;
            }
        }
 
        if (isBeauty) {
            cout<< "YES"<<endl;
        } else {
            cout<< "NO"<<endl;
        }
    }*/