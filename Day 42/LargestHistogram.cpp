#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void printArr(vector<int> arr) {
    int n = arr.size();
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

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
    cout << "Next Smaller : ";
    printArr(ans);
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
    cout << "Prev Smaller : ";
    printArr(ans);
    return ans;
}

int largestHistogram(vector<int> a, int n) {
    vector<int> next = nextSmaller(a, n);
    vector<int> prev = prevSmaller(a, n);
    int maxArea = 0;
    cout<<"Area s : ";
    for(int i = 0; i < n; i++) {
        if(next[i] == -1) next[i] = n;
        int width = next[i] - prev[i] - 1;
        int area = width * a[i];
        cout<<area<<" ";
        maxArea = max(maxArea, area);
    }
    return maxArea;
}

int main () 
{
    vector<int> a = {2,2,2,2,2};
    cout<<"Orignal Arry : ";
    printArr(a);
    int n = a.size();

    cout <<"\nLargest Area : "<< largestHistogram(a, n) << endl<<endl;

    vector<int> b = {4 , 5 , 2 , 10 , 8};
    cout<<"Orignal Arry : ";
    printArr(b);
    int x = b.size();

    cout <<"\nLargest Area : "<< largestHistogram(b, x) << endl;



    return 0;
}