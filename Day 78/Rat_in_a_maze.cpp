//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
public:
    bool isSafe(const vector<vector<int>>& maze, vector<vector<int>>& visited, int newX, int newY, int n) {
        return newX >= 0 && newX < n && newY >= 0 && newY < n && maze[newX][newY] == 1 && visited[newX][newY] == 0;
    }

    void paths(vector<vector<int>>& maze, vector<vector<int>>& visited, vector<string>& ans, string path, int x, int y, int n) {
        if (x == n - 1 && y == n - 1) {  // Reached the bottom-right corner
            ans.push_back(path);
            return;
        }  

        int newX, newY;

        // For downward 'D'
        newX = x + 1;
        newY = y;
        if (isSafe(maze, visited, newX, newY, n)) {
            visited[newX][newY] = 1;
            path.push_back('D');
            paths(maze, visited, ans, path, newX, newY, n);
            visited[newX][newY] = 0;
            path.pop_back();
        }

        // For Upward 'U'
        newX = x - 1;
        newY = y;
        if (isSafe(maze, visited, newX, newY, n)) {
            visited[newX][newY] = 1;
            path.push_back('U');
            paths(maze, visited, ans, path, newX, newY, n);
            visited[newX][newY] = 0;
            path.pop_back();
        }

        // For Rightward 'R'
        newX = x;
        newY = y + 1;
        if (isSafe(maze, visited, newX, newY, n)) {
            visited[newX][newY] = 1;
            path.push_back('R');
            paths(maze, visited, ans, path, newX, newY, n);
            visited[newX][newY] = 0;
            path.pop_back();
        }

        // For Leftward 'L'
        newX = x;
        newY = y - 1;
        if (isSafe(maze, visited, newX, newY, n)) {
            visited[newX][newY] = 1;
            path.push_back('L');
            paths(maze, visited, ans, path, newX, newY, n);
            visited[newX][newY] = 0;
            path.pop_back();
        }
    }

    vector<string> findPath(vector<vector<int>>& maze) {
        vector<string> ans;
        int n = maze.size();  // Define `n` based on the maze size
        vector<vector<int>> visited(n, vector<int>(n, 0));

        if (maze[0][0] == 1) {  // Only start if the start cell is open
            visited[0][0] = 1;  // Mark the starting cell as visited
            paths(maze, visited, ans, "", 0, 0, n);
        }

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

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
// 4
// 1 0 0 0
// 1 1 0 1 
// 1 1 0 0 
// 0 1 1 1