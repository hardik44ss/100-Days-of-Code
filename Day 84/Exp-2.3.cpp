/*
    Important Bullet Points for the Experiment (Breadth-First Search and Depth-First Search)
    
    Objective: Implement Breadth-First Search (BFS) and Depth-First Search (DFS) algorithms to traverse a graph.
    
    Data Structure: Graph represented using an adjacency list.

    BFS (Breadth-First Search):
    - Uses a queue for traversal.
    - Starts from the given source vertex and visits all vertices level by level.
    - Efficient for finding the shortest path in an unweighted graph.
    
    DFS (Depth-First Search):
    - Uses recursion or a stack for traversal.
    - Starts from the given source vertex and explores as far as possible along each branch before backtracking.
    - Efficient for exploring connected components or solving pathfinding problems.
    
    Time Complexity: Both BFS and DFS run in O(V + E) time where V is the number of vertices and E is the number of edges.
*/
#include <iostream>
#include <list>
#include <queue>
#include <stack>

using namespace std;

class Graph {
    int V; // Number of vertices 
    list<int> *adj; // Pointer to an array containing adjacency lists

public:
    Graph(int V); // Constructor
    void addEdge(int v, int w); // Function to add an edge to graph
    void BFS(int s); // Function to perform BFS
    void DFS(int s); // Function to perform DFS
    void DFSUtil(int v, bool visited[]); // Utility function for DFS
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w); // Add w to v’s list.
}

void Graph::BFS(int s) {
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;

    // Create a queue for BFS
    queue<int> queue;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push(s);

    while(!queue.empty()) {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        cout << s << " ";
        queue.pop();

        // Get all adjacent vertices of the dequeued vertex s
        // If an adjacent has not been visited, then mark it
        // visited and enqueue it
        for (auto adjacent: adj[s]) {
            if (!visited[adjacent]) {
                visited[adjacent] = true;
                queue.push(adjacent);
            }
        }
    }
}

void Graph::DFSUtil(int v, bool visited[]) {
    // Mark the current node as visited and print it
    visited[v] = true;
    cout << v << " ";

    // Recur for all the vertices adjacent to this vertex
    for (auto adjacent: adj[v])
        if (!visited[adjacent])
            DFSUtil(adjacent, visited);
}

void Graph::DFS(int s) {
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Call the recursive helper function to print DFS traversal
    DFSUtil(s, visited);
}

int main() {
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Breadth First Traversal (starting from vertex 2): ";
    g.BFS(2);
    cout << endl;

    cout << "Depth First Traversal (starting from vertex 2): ";
    g.DFS(2);
    cout << endl;

    return 0;
}
/*
Graph:
    0  -> 1
    ^   / 
    |  /  |
    v v   v
    2 --> 3-~
          \_/
Breadth First Traversal (starting from vertex 2): 2 0 3 1 
Depth First Traversal (starting from vertex 2): 2 0 1 3 
*/