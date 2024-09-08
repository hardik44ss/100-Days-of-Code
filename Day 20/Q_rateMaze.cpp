//Rate maze problem
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    bool check(int x, int y, int n, vector<vector<int>>& mat, vector<vector<int>>& visited){
        
        if(x >= 0 && y >= 0 && x < n && y < n && mat[x][y] == 1 && visited[x][y] == 0){
            return true;
        } else {
            return false;
        }
    }
    
    void solve(vector<vector<int>>& mat, int x, int y, int n, vector<vector<int>>& visited, string path, vector<string>& ans)
    {
        //Base case
        if(x == n-1 && y == n-1){
            ans.push_back(path);
            return;
        }
        
        visited[x][y] = 1;
        
        //Downward 
        int newX = x+1;
        int newY = y;
        if(check(newX, newY, n, mat, visited)){
            path.push_back('D');
            solve(mat, newX, newY, n, visited, path, ans);
            path.pop_back();
        }
        
        //Left
        newX = x;
        newY = y-1;
        if(check(newX, newY, n, mat, visited)){
            path.push_back('L');
            solve(mat, newX, newY, n, visited, path, ans);
            path.pop_back();
        }
        
        //Right
        newX = x;
        newY = y+1;
        if(check(newX, newY, n, mat, visited)){
            path.push_back('R');
            solve(mat, newX, newY, n, visited, path, ans);
            path.pop_back();
        }
        
        //Upward
        newX = x-1;
        newY = y;
        if(check(newX, newY, n, mat, visited)){
            path.push_back('U');
            solve(mat, newX, newY, n, visited, path, ans);
            path.pop_back();
        }
        
        visited[x][y] = 0;  // Backtrack
    }

    vector<string> findPath(vector<vector<int>>& mat) {
        vector<string> ans;
        int n = mat.size();
        if(mat[0][0] == 0){
            return ans;
        }
        int srcx = 0;
        int srcy = 0;
        
        vector<vector<int>> visited(n, vector<int>(n, 0));
        string path = "";
        solve(mat, srcx, srcy, n, visited, path, ans);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends