#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

// Prim's Algorithm: Builds MST by expanding from a single vertex using minimum weight edge.
// Kruskal's Algorithm: Builds MST by sorting edges and adding the smallest edges while avoiding cycles.
// Both find the MST but use different approaches:
// - Prim’s: Expands MST from a starting vertex.
// - Kruskal’s: Adds edges in increasing order of weight, ensuring no cycles.

int minKey(const vector<int>& key, const vector<bool>& mstSet, int V) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (!mstSet[v] && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

void printMST_Prim(const vector<int>& parent, const vector<vector<int>>& graph, int V) {
    cout << "Prim's MST:\n";
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << " \n";
}

void primMST(const vector<vector<int>>& graph, int V) {
    vector<int> parent(V);
    vector<int> key(V, INT_MAX);
    vector<bool> mstSet(V, false);

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet, V);
        mstSet[u] = true;

        for (int v = 0; v < V; v++)
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    printMST_Prim(parent, graph, V);
}

class Graph {
public:
    int vertices, E;
    vector<pair<int, pair<int, int>>> edges;

    Graph(int V, int E) {
        this->vertices = V;
        this->E = E;
    }

    void addEdge(int u, int v, int w) {
        edges.push_back({w, {u, v}});
    }

    int find(int parent[], int i) {
        if (parent[i] == -1)
            return i;
        return find(parent, parent[i]);
    }

    void Union(int parent[], int x, int y) {
        int xset = find(parent, x);
        int yset = find(parent, y);
        parent[xset] = yset;
    }

    void KruskalMST() {
        sort(edges.begin(), edges.end());
        vector<pair<int, pair<int, int>>> result;
        int parent[vertices];
        fill_n(parent, vertices, -1);

        for (auto it : edges) {
            int u = it.second.first;
            int v = it.second.second;
            int set_u = find(parent, u);
            int set_v = find(parent, v);

            if (set_u != set_v) {
                result.push_back(it);
                Union(parent, set_u, set_v);
            }
        }

        cout << "Kruskal's MST:\n";
        cout << "Edge \tWeight\n";
        for (auto it : result)
            cout << it.second.first << " - " << it.second.second << "\t" << it.first << " \n";
    }
};

int main() {
    int V = 5;
    vector<vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(graph, V);

    Graph g(V, 7);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);

    g.KruskalMST();

    return 0;
}

/*
Expected Output:

Prim's MST:
Edge    Weight
0 - 1   2 
1 - 2   3 
0 - 3   6 
1 - 4   5 

Kruskal's MST:
Edge    Weight
0 - 1   2 
1 - 2   3 
0 - 3   6 
1 - 4   5 
*/