#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> nextSmaller(vector<int> arr, int n) {
    vector<int> ans(n, -1);
    stack<int> s;
    for(int i = 0; i < n; i++) {
        while(!s.empty() && arr[s.top()] > arr[i]) {
            ans[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }
    return ans;
}

vector<int> prevSmaller(vector<int> arr, int n) {
    vector<int> ans(n, -1);
    stack<int> s;
    for(int i = n - 1; i >= 0; i--) {
        while(!s.empty() && arr[s.top()] > arr[i]) {
            ans[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }
    return ans;
}

int main () 
{
    vector<int> a = {4, 5, 2, 10, 8};
    int n = a.size();
    
    vector<int> next = nextSmaller(a, n);
    for(int i = 0; i < n; i++) {
        cout << next[i] << " ";
    }
    cout << endl;

    vector<int> prev = prevSmaller(a, n);
    for(int i = 0; i < n; i++) {
        cout << prev[i] << " ";
    }
    cout << endl;

    return 0;
}