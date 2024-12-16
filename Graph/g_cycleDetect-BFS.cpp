#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool detectCycle(int start, vector<vector<int>>& adj, vector<bool>& visited) {
        vector<int> parent(adj.size(), -1);
        queue<int> q;
        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                    parent[neighbor] = node;
                } else if (parent[node] != neighbor) {
                    return true;  // Cycle detected
                }
            }
        }

        return false;
    }

    bool isCycle(vector<vector<int>>& adj) {
        int v = adj.size();
        vector<bool> visited(v, false);

        for (int i = 0; i < v; i++) {
            if (!visited[i]) {  // Only start BFS from unvisited nodes
                if (detectCycle(i, adj, visited)) return true;
            }
        }

        return false;  // No cycle found
    }
};

// Driver Code
int main() {
    // Example 1: Connected Graph with a Cycle
    {
        cout << "Example 1: Connected Graph with a Cycle\n";
        int V = 5;
        vector<vector<int>> adj(V);

        // Adding edges to the graph
        adj[0].push_back(1);
        adj[1].push_back(0);
        adj[1].push_back(2);
        adj[2].push_back(1);
        adj[2].push_back(3);
        adj[3].push_back(2);
        adj[3].push_back(4);
        adj[4].push_back(3);
        adj[4].push_back(1);
        adj[1].push_back(4);

        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "Cycle detected\n";
        else
            cout << "No cycle detected\n";
    }

    // Example 2: Disconnected Graph without a Cycle
    {
        cout << "Example 2: Disconnected Graph without a Cycle\n";
        int V = 6;
        vector<vector<int>> adj(V);

        // Adding edges to the graph
        adj[0].push_back(1);
        adj[1].push_back(0);
        adj[2].push_back(3);
        adj[3].push_back(2);
        adj[4].push_back(5);
        adj[5].push_back(4);

        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "Cycle detected\n";
        else
            cout << "No cycle detected\n";
    }

    return 0;
}

/*
Example 1: Connected Graph with a Cycle
Graph:
    0 -- 1 -- 2
         |    |
         4 -- 3

Explanation:
The graph has 5 vertices (0 to 4) and the following edges:
0-1, 1-2, 2-3, 3-4, 4-1

The graph contains a cycle: 1-2-3-4-1

Example 2: Disconnected Graph without a Cycle
Graph:
    0 -- 1    2 -- 3    4 -- 5

Explanation:
The graph has 6 vertices (0 to 5) and the following edges:
0-1, 2-3, 4-5

The graph is disconnected and does not contain any cycles.
*/