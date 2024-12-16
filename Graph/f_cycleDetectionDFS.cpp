//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
 public:
    bool detectCycle(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;

        for (int j = 0; j < adj[node].size(); j++) {
            int neighbor = adj[node][j];

            if (neighbor == parent) continue;  // Don't revisit the parent

            if (visited[neighbor]) return true;  // Cycle detected
            
            if (!visited[neighbor] && detectCycle(neighbor, node, adj, visited)) 
                return true;
        }

        return false;
    }

    bool isCycle(vector<vector<int>>& adj) {
        int v = adj.size();
        vector<bool> visited(v, false);  // Initialize visited array

        // Connected Graph
        // return detectCycle(adj[0][0] , -1, adj , visited);

        //Disconnected Graph
        for (int i = 0; i < v; i++) {
            if (!visited[i]) {  // Only start DFS from unvisited nodes
                if (detectCycle(i, -1, adj, visited)) return true;
            }
        }

        return false;  // No cycle found
    }

};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends