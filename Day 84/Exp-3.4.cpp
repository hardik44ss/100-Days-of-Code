#include <iostream>
#include <vector>
#include <climits>

using namespace std;

/*
 * Experiment 10: Implementation of Bellman-Ford Algorithm
 * 
 * Course Outcome: 5
 * 
 * - The Bellman-Ford algorithm is used to find the shortest paths from a source vertex to all other vertices in a weighted graph.
 * - It can handle graphs with negative weight edges, but cannot work with negative weight cycles.
 * - The algorithm works by relaxing all edges V-1 times, where V is the number of vertices in the graph.
 * - After relaxation, it checks for negative weight cycles.
 * 
 * Steps:
 * 1. Initialize distances from the source vertex to all other vertices as infinity, except the source itself.
 * 2. For each vertex, relax all edges V-1 times.
 * 3. After relaxing, check for negative weight cycles.
 * 4. If no negative cycle is detected, print the shortest distances.
 * 
 * Relevant Book/Standard Code: Algorithms for shortest path in graphs.
 */

struct Edge {
    int source, destination, weight;
};

class Graph {
public:
    int V, E;
    vector<Edge> edges;

    Graph(int V, int E) {
        this->V = V;
        this->E = E;
        edges.resize(E);
    }

    void addEdge(int u, int v, int w, int index) {
        edges[index] = {u, v, w};
    }

    void bellmanFord(int src) {
        vector<int> distance(V, INT_MAX);
        distance[src] = 0;

        // Relax all edges V-1 times
        for (int i = 1; i <= V - 1; ++i) {
            for (int j = 0; j < E; ++j) {
                int u = edges[j].source;
                int v = edges[j].destination;
                int weight = edges[j].weight;

                if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                    distance[v] = distance[u] + weight;
                }
            }
        }

        // Check for negative weight cycles
        for (int i = 0; i < E; ++i) {
            int u = edges[i].source;
            int v = edges[i].destination;
            int weight = edges[i].weight;

            if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                cout << "Graph contains negative weight cycle" << endl;
                return;
            }
        }

        printSolution(distance);
    }

    void printSolution(vector<int> distance) {
        cout << "Vertex\tDistance from Source" << endl;
        for (int i = 0; i < V; ++i) {
            cout << i << "\t" << distance[i] << endl;
        }
    }
};

int main() {
    int V = 5; // Number of vertices in graph
    int E = 8; // Number of edges in graph
    Graph graph(V, E);

    graph.addEdge(0, 1, -1, 0);
    graph.addEdge(0, 2, 4, 1);
    graph.addEdge(1, 2, 3, 2);
    graph.addEdge(1, 3, 2, 3);
    graph.addEdge(1, 4, 2, 4);
    graph.addEdge(3, 2, 5, 5);
    graph.addEdge(3, 1, 1, 6);
    graph.addEdge(4, 3, -3, 7);

    int source = 0;
    graph.bellmanFord(source);

    return 0;
}
/*
Vertex	Distance from Source
0	0
1	-1
2	2
3	-2
4	1
*/