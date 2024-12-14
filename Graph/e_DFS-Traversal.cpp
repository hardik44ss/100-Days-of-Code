#include <iostream>
#include <vector>
using namespace std;

class Graph {
public:
    // Depth First Search function
    void DFS(int node, vector<vector<int>>& adj, vector<int>& ans, vector<bool>& visited) {
        ans.push_back(node);
        visited[node] = true;
        
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                DFS(neighbor, adj, ans, visited);
            }
        }
    }

    // Function to return a list containing the DFS traversal of the graph
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        int v = adj.size();
        vector<bool> visited(v, false);
        vector<int> ans;
        
        // Assuming the graph is connected and starting DFS from node 0
        DFS(0, adj, ans, visited);
        return ans;
    }
};

// Example usage
int main() {
    Graph g;
    vector<vector<int>> adj = {
        {1, 2},   // Neighbors of node 0
        {0, 3},   // Neighbors of node 1
        {0, 4},   // Neighbors of node 2
        {1},      // Neighbors of node 3
        {2}       // Neighbors of node 4
    };
    
    vector<int> result = g.dfsOfGraph(adj);
    
    cout << "DFS Traversal: ";
    for (int node : result) {
        cout << node << " ";
    }
    return 0;
}
