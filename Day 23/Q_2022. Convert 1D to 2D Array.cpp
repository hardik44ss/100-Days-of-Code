#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> convertTo2D(vector<int> arr, int n, int m)
{
    vector<vector<int>> ans(n, vector<int>(m));
    int k = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            ans[i][j] = arr[k++];
        }
    }
    return ans;
}

int main () 
{
    int n, m;
    cin >> n >> m;
    vector<int> arr(n*m);
    for(int i = 0; i < n*m; i++)
    {
        cin >> arr[i];
    }
    vector<vector<int>> ans = convertTo2D(arr, n, m);   
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}