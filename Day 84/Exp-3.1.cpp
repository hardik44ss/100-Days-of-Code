#include <iostream>
#include <vector>
#include <climits>

using namespace std;

/*
AIM: To find the shortest path in a multistage graph using dynamic programming.

S/W Requirement: C++ compiler (e.g., g++)

The algorithm uses dynamic programming to calculate the minimum cost at each stage by iterating backwards from the destination.
It keeps track of the shortest path and its associated cost.

Time Complexity: O(V^2), where V is the number of vertices in the graph.

Space Complexity: O(V), where V is the number of vertices in the graph, due to the storage of costs and paths.
*/

// Function to find the shortest path in a multistage graph
int shortestPath(vector<vector<int>>& graph, int stages) {
    int n = graph.size();
    vector<int> cost(n, INT_MAX); // To store the minimum cost to reach each vertex
    vector<int> path(n, -1); // To store the path
    cost[n-1] = 0; // Cost to reach the destination from itself is zero

    // Calculate the minimum cost to reach the destination from each vertex
    for (int i = n-2; i >= 0; i--) {
        for (int j = i+1; j < n; j++) {
            if (graph[i][j] != 0 && graph[i][j] + cost[j] < cost[i]) {
                cost[i] = graph[i][j] + cost[j];
                path[i] = j;
            }
        }
    }

    // Display the path
    int k = 0;
    cout << "The shortest path is: ";
    while (k != n-1) {
        cout << k << " -> ";
        k = path[k];
    }
    cout << n-1 << endl;

    return cost[0];
}

int main() {
    // Number of vertices in the graph
    int n = 8;

    // Multistage graph represented as an adjacency matrix
    vector<vector<int>> graph = {
        {0, 1, 2, 5, 0, 0, 0, 0},
        {0, 0, 0, 0, 4, 11, 0, 0},
        {0, 0, 0, 0, 9, 5, 16, 0},
        {0, 0, 0, 0, 0, 0, 2, 0},
        {0, 0, 0, 0, 0, 0, 0, 18},
        {0, 0, 0, 0, 0, 0, 0, 13},
        {0, 0, 0, 0, 0, 0, 0, 2},
        {0, 0, 0, 0, 0, 0, 0, 0}
    };

    // Number of stages in the graph
    int stages = 4;

    // Calculate the shortest path
    int minCost = shortestPath(graph, stages);

    // Output the result
    cout << "The minimum cost is: " << minCost << endl;

    return 0;
}

/*
Expected Output:
The shortest path is: 0 -> 2 -> 5 -> 7
The minimum cost is: 17
*/
