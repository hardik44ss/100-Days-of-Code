#include <bits/stdc++.h>
using namespace std;

// Structure for a tree node
struct Node {
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Optimized solve function with map for faster lookups
Node* solve(int in[], int pre[], int &index, int inStart, int inEnd, int n, map<int, int> &nodeToIndex) {
    // Base case: if index exceeds array bounds or invalid inorder range
    if (index >= n || inStart > inEnd) return NULL;

    // Extract current root element from preorder traversal
    int element = pre[index++];
    Node* curr = new Node(element);

    // Get the position of the current root in inorder traversal using the map
    int pos = nodeToIndex[element];

    // Recursively construct the left and right subtrees
    curr->left = solve(in, pre, index, inStart, pos - 1, n, nodeToIndex);
    curr->right = solve(in, pre, index, pos + 1, inEnd, n, nodeToIndex);

    return curr;
}

// Function to build the binary tree from inorder and preorder traversals
Node* buildTree(int in[], int pre[], int n) {
    // Create a map to store the index of each element in inorder traversal
    map<int, int> nodeToIndex;

    // Fill the map with inorder element indices
    for (int i = 0; i < n; i++) {
        nodeToIndex[in[i]] = i;
    }

    // Initialize the index for preorder traversal
    int index = 0;

    // Recursively build the tree
    Node* ans = solve(in, pre, index, 0, n - 1, n, nodeToIndex);

    return ans;
}

void printPostorder(Node* root) {
    if (root == NULL) return;
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->data << " ";
}

// Example usage
int main() {
    int in[] = {4, 2, 5, 1, 6, 3};
    int pre[] = {1, 2, 4, 5, 3, 6};
    int n = sizeof(in) / sizeof(in[0]);

    Node* root = buildTree(in, pre, n);

    cout << "Post Traversal of constructed tree: ";
    printPostorder(root);

    return 0;
}
