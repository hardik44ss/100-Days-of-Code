#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void DFS(int node, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st) {
    visited[node] = true;

    for (int neighbour : adj[node]) {
        if (!visited[neighbour]) {
            DFS(neighbour, adj, visited, st);
        }
    }
    st.push(node);
}

vector<int> topologicalSort(vector<vector<int>>& adj) {
    vector<int> ans;
    int v = adj.size();
    stack<int> st;
    vector<bool> visited(v, false);

    for (int i = 0; i < v; i++) {
        if (!visited[i]) 
            DFS(i, adj, visited, st);
    }

    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

// Driver Code
int main() {
    // Example: Directed Acyclic Graph (DAG)
    int V = 6;
    vector<vector<int>> adj(V);

    // Adding edges to the graph
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);


    vector<int> ans = topologicalSort(adj);

    // Output the result
    cout << "Topological Sort of the given graph: ";
    for (size_t i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
Example Graph:
    5 --> 2 --> 3 --> 1
    |           ^
    v           |
    0 --> 4 --> 1

Explanation:
The graph has 6 vertices (0 to 5) and the following directed edges:
5 -> 2, 5 -> 0, 4 -> 0, 4 -> 1, 2 -> 3, 3 -> 1

Input:
No user input required as the graph is predefined in the code.

Output:
Topological Sort of the given graph: 5 4 2 3 1 0
*/