#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Helper function to find the path from root to the given node
bool solve(Node* root, int node, vector<Node*>& path) {
    if (root == NULL) return false;
    
    path.push_back(root); // Add current node to the path
    
    // Check if the current node is the target node
    if (root->data == node) return true;
    
    // Recursively check left and right subtrees
    if ((root->left && solve(root->left, node, path)) || (root->right && solve(root->right, node, path)))
        return true;
    
    // If node not found, backtrack and remove current node from path
    path.pop_back();
    return false;
}

// Function to find the Kth ancestor of a given node in the binary tree
int kthAncestor(Node *root, int k, int node) {
    vector<Node*> path;  // Vector to store the path from root to the node
    
    // Find the path to the given node
    if (!solve(root, node, path)) return -1;

    int pathSize = path.size();
    
    // If the path length is less than or equal to k, return -1 (no Kth ancestor)
    if (pathSize <= k) return -1;

    // The Kth ancestor is at index (pathSize - k - 1) in the path
    return path[pathSize - k - 1]->data;
}

int main() {
    // Create the binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int node = 5, k = 2;
    cout << "The " << k << "th ancestor of node " << node << " is: " << kthAncestor(root, k, node) << endl;

    return 0;
}
/*
          1
         / \
        2   3
       / \  / \
      4   5 6  7
    
*/