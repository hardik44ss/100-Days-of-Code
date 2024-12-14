#include <iostream>
#include <vector>

using namespace std;

int main() {
    int vertex, edge;
    cout << "Enter number of vertices: ";
    cin >> vertex;
    cout << "Enter number of edges: ";
    cin >> edge;

    vector<vector<pair<int, int>>> adjList(vertex);

    int u, v, weight;
    char graphType;
    cout << "Enter graph type (u for undirected, d for directed, w for weighted undirected, W for weighted directed): ";
    cin >> graphType;

    for (int i = 0; i < edge; i++) {
        if (graphType == 'w' || graphType == 'W') {
            // Weighted Graph
            cin >> u >> v >> weight;
            adjList[u].push_back({v, weight});
            if (graphType == 'w') {
                // Undirected Weighted Graph
                adjList[v].push_back({u, weight});
            }
        } else {
            // Unweighted Graph
            cin >> u >> v;
            adjList[u].push_back({v, 1});
            if (graphType == 'u') {
                // Undirected Unweighted Graph
                adjList[v].push_back({u, 1});
            }
        }
    }

    // Printing the adjacency list
    for (int i = 0; i < vertex; i++) {
        cout << "Vertex " << i << ":";
        for (const auto& pair : adjList[i]) {
            cout << " -> (" << pair.first << ", " << pair.second << ")";
        }
        cout << endl;
    }

    return 0;
}

/*
Example 1: Undirected Unweighted Graph
    Input:
    Enter number of vertices: 3
    Enter number of edges: 3
    Enter graph type (u for undirected, d for directed, w for weighted undirected, W for weighted directed): u
    0 1
    1 2
    2 0

    Output:
    Vertex 0: -> (1, 1) -> (2, 1)
    Vertex 1: -> (0, 1) -> (2, 1)
    Vertex 2: -> (1, 1) -> (0, 1)   

Example 2: Directed Unweighted Graph
    Input:
    Enter number of vertices: 3
    Enter number of edges: 3
    Enter graph type (u for undirected, d for directed, w for weighted undirected, W for weighted directed): d
    0 1
    1 2
    2 0

    Output:
    Vertex 0: -> (1, 1)
    Vertex 1: -> (2, 1)
    Vertex 2: -> (0, 1)

Example 3: Undirected Weighted Graph
    Input:
    Enter number of vertices: 3
    Enter number of edges: 3
    Enter graph type (u for undirected, d for directed, w for weighted undirected, W for weighted directed): w
    0 1 5
    1 2 3
    2 0 4

    Output:
    Vertex 0: -> (1, 5) -> (2, 4)
    Vertex 1: -> (0, 5) -> (2, 3)
    Vertex 2: -> (1, 3) -> (0, 4)

Example 4: Directed Weighted Graph
    Input:
    Enter number of vertices: 3
    Enter number of edges: 3
    Enter graph type (u for undirected, d for directed, w for weighted undirected, W for weighted directed): W
    0 1 5
    1 2 3
    2 0 4

    Output:
    Vertex 0: -> (1, 5)
    Vertex 1: -> (2, 3)
    Vertex 2: -> (0, 4)
*/