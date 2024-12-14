#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> bfsTraveresal(vector<vector<int>> adj) {

    int v = adj.size();
    vector<int> ans;

    vector<bool> visited(v, false);
    queue<int> q;
    q.push(0);
    visited[0] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for (size_t i = 0; i < adj[node].size(); i++) {

            if (!visited[adj[node][i]]) {

                q.push(adj[node][i]);
                visited[adj[node][i]] = true;
            }
        }
    }

    return ans;

}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        // Now using vector of vectors instead of array of vectors
        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u); // For undirected graph, add both u->v and v->u
        }

        vector<int> ans = bfsTraveresal(adj);
        for (size_t i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
  return 0;
}

/*
Example Input 1:
1
5 4
0 1
0 2
1 3
1 4

Example Output 1:
0 1 2 3 4

Explanation:
The BFS traversal starts from vertex 0 and visits vertices in the following order: 0 -> 1 -> 2 -> 3 -> 4.

Example Input 2:
1
4 4
0 1
0 2
1 2
2 3

Example Output 2:
0 1 2 3

Explanation:
The BFS traversal starts from vertex 0 and visits vertices in the following order: 0 -> 1 -> 2 -> 3.
*/