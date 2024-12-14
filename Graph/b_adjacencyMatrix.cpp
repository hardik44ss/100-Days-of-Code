#include <iostream>
#include <vector>

using namespace std;

int main() {
    int vertex, edge;
    cout << "Enter number of vertices: ";
    cin >> vertex;
    cout << "Enter number of edges: ";
    cin >> edge;

    vector<vector<int>> adjMat(vertex, vector<int>(vertex, 0));

    int u, v, weight;
    char graphType;
    cout << "Enter graph type (u for undirected, d for directed, w for weighted undirected, W for weighted directed): ";
    cin >> graphType;

    for (int i = 0; i < edge; i++) {
        if (graphType == 'w' || graphType == 'W') {
            // Weighted Graph
            cin >> u >> v >> weight;
            adjMat[u][v] = weight;
            if (graphType == 'w') { 
                // Undirected Weighted Graph
                adjMat[v][u] = weight;
            }
        } else {
            // Unweighted Graph
            cin >> u >> v;
            adjMat[u][v] = 1;
            if (graphType == 'u') {
                // Undirected Unweighted Graph
                adjMat[v][u] = 1;
            }
        }
    }

    // Printing the adjacency matrix
    for (int i = 0; i < vertex; i++) {
        for (int j = 0; j < vertex; j++) {
            cout << adjMat[i][j] << " ";
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
0 1 1 
1 0 1 
1 1 0 

Example 2: Directed Unweighted Graph
Input:
Enter number of vertices: 3
Enter number of edges: 3
Enter graph type (u for undirected, d for directed, w for weighted undirected, W for weighted directed): d
0 1
1 2
2 0

Output:
0 1 0 
0 0 1 
1 0 0 

Example 3: Undirected Weighted Graph
Input:
Enter number of vertices: 3
Enter number of edges: 3
Enter graph type (u for undirected, d for directed, w for weighted undirected, W for weighted directed): w
0 1 5
1 2 3
2 0 4

Output:
0 5 4 
5 0 3 
4 3 0 

Example 4: Directed Weighted Graph
Input:
Enter number of vertices: 3
Enter number of edges: 3
Enter graph type (u for undirected, d for directed, w for weighted undirected, W for weighted directed): W
0 1 5
1 2 3
2 0 4

Output:
0 5 0 
0 0 3 
4 0 0 
*/