class Solution {
    public:
        int countUnguarded(int m, int n, vector<vector<int>>& g, vector<vector<int>>& w) {
            vector<vector<int>> vis(m, vector<int>(n, 0));
            
            // Mark walls = 2
            for (auto val : w) {
                vis[val[0]][val[1]] = 2;
            }
    
            // Mark guards = 3
            for (auto val : g) {
                vis[val[0]][val[1]] = 3;
            }
    
            // Traverse in four directions to mark guarded cells
            for (auto val : g) {
                int row = val[0], col = val[1];
    
                // Down
                for (int i = row + 1; i < m; i++) {
                    if (vis[i][col] == 2 || vis[i][col] == 3) break; // Stop at wall or guard
                    vis[i][col] = 1; // Mark as guarded
                }
    
                // Up
                for (int i = row - 1; i >= 0; i--) {
                    if (vis[i][col] == 2 || vis[i][col] == 3) break;
                    vis[i][col] = 1;
                }
    
                // Right
                for (int i = col + 1; i < n; i++) {
                    if (vis[row][i] == 2 || vis[row][i] == 3) break;
                    vis[row][i] = 1;
                }
    
                // Left
                for (int i = col - 1; i >= 0; i--) {
                    if (vis[row][i] == 2 || vis[row][i] == 3) break;
                    vis[row][i] = 1;
                }
            }
    
            // Count unguarded cells
            int unguarded = 0;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (vis[i][j] == 0) unguarded++;
                }
            }
    
            return unguarded;
        }
    };