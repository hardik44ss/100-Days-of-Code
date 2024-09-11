#include<iostream>
#include<vector>
using namespace std;

int alterSum(vector<int> arr)
{
    int sum = 0;
    for(int i = 0; i < arr.size(); i++)
    {
        if(i % 2 == 0)
        {
            sum += arr[i];
        }
        else
        {
            sum -= arr[i];
        }
    }
    return sum;
}

int main () 
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << alterSum(arr) << endl;
    }
    return 0;
}
/*
Input : 
4
4
1 2 3 17
1
100
2
100 100
5
3 1 4 1 5
*/