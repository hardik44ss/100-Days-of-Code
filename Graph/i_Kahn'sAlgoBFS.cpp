#include <iostream>
#include <vector>
#include <queue>

using namespace std;
 vector<int> topologicalSort(vector<vector<int>> & adj){
        
        vector<int> ans;
        int v=adj.size();
        vector<int> inDegree(v,0);
        
        for(int i = 0;i<v;i++){
            for(int j : adj[i]){
                inDegree[j]++;
            }
        }
        queue<int> q;
        for(int i =0 ;i<v;i++){
            if(inDegree[i]==0) q.push(i);
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for(int neighbour : adj[node]){
                inDegree[neighbour]--;
                if(inDegree[neighbour]==0){
                    q.push(neighbour);
                }
            }
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
    for (int i = 0; i < ans.size(); i++) {
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