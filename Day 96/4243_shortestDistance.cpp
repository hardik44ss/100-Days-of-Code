/*
Problem Statement:
Given a number of nodes `n` and a list of queries where each query adds a directed edge between two nodes, find the shortest distance from node 0 to node n-1 after each query.

Example:
Input: n = 5, queries = [[0, 2], [2, 4], [1, 3]]
Output: [2, 2, 2]
Explanation: 
- After the first query, the shortest path from 0 to 4 is 0 -> 2 -> 4 with distance 2.
- After the second query, the shortest path from 0 to 4 is still 0 -> 2 -> 4 with distance 2.
- After the third query, the shortest path from 0 to 4 is still 0 -> 2 -> 4 with distance 2.

Constraints:
- 2 <= n <= 1000
- 1 <= queries.length <= 1000
- 0 <= queries[i][0], queries[i][1] < n
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
    int bfs(int start, int end, int n, vector<vector<int>>& graph) {
        vector<int> dist(n, INT_MAX);
        queue<int> q;
        q.push(start);
        dist[start] = 0;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int u : graph[curr]) {
                if (dist[u] > dist[curr] + 1) {
                    dist[u] = dist[curr] + 1;
                    q.push(u);
                }
            }
        }

        return dist[end];
    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> answer;
        vector<vector<int>> graph(n);

        for (int i = 0; i < n - 1; i++) {
            graph[i].push_back(i + 1);
        }

        for (auto query : queries) {
            int u = query[0], v = query[1];
            graph[u].push_back(v);
            answer.push_back(bfs(0, n - 1, n, graph));
        }

        return answer;
    }
};

int main() {
    // Predefined input
    int n = 5;
    vector<vector<int>> queries = {{0, 2}, {2, 4}, {1, 3}};

    Solution sol;
    vector<int> result = sol.shortestDistanceAfterQueries(n, queries);

    // Output the result
    cout << "Shortest distances after each query: ";
    for (int dist : result) {
        cout << dist << " ";
    }
    cout << endl;

    return 0;
}

/*
Expected Output:
Shortest distances after each query: 2 2 2
*/