#include<iostream>
#include<stack>
#include<queue>

using namespace std;

vector<int> printFirstNegativeInteger(int A[], int N, int K ){
    deque<int> dq;
    vector<int> ans;

    //Process the first window 
    for(int i =0 ; i<K ; i++){
        if(A[i] < 0 ){
            dq.push_back(i);
        }
    }

    if(dq.size() > 0) {
        ans.push_back(A[dq.front()]);
    }else{
        ans.push_back(0);
    }

    for(int i = K ; i<N ;i++){
        if(!dq.empty() && (i-dq.front() >= K)){
            dq.pop_front();
        }

        if(A[i] < 0) dq.push_back(i);

        if(dq.size() > 0) {
            ans.push_back(A[dq.front()]);
        }else{
            ans.push_back(0);
        }
    }
    return ans;
}
void display(queue<int> q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}

int main () 
{
    int A[] = {12, -1, -7, 8, -15, 30, 16, 28};
    int N = 8;
    int K = 3;
    cout<<endl;
    vector<int> ans = printFirstNegativeInteger(A, N, K);
    for(unsigned int i = 0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}