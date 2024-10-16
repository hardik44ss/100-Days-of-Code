#include <bits/stdc++.h>
using namespace std;

// Structure for a tree node
struct Node {
    int data;
    Node *left, *right;
    
    // Constructor to create a new tree node
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to solve the problem recursively
pair<int, int> solve(Node* root) {
    // Base case: if the node is null, return 0 for both values
    if (root == NULL) return make_pair(0, 0);

    // Recursively solve for the left and right subtrees
    pair<int, int> left = solve(root->left);
    pair<int, int> right = solve(root->right);

    pair<int, int> res;

    // First value: Include the current node's data + the second values of left and right
    res.first = root->data + left.second + right.second;

    // Second value: Maximum of first and second for both left and right
    res.second = max(left.first, left.second) + max(right.first, right.second);

    return res;
}

// Function to get the maximum sum of non-adjacent nodes
int getMaxSum(Node* root) {
    pair<int, int> ans = solve(root);

    // Return the maximum of including or excluding the root
    return max(ans.first, ans.second);
}

// Helper function to create a binary tree
Node* newNode(int val) {
    Node* node = new Node(val);
    return node;
}

int main() {
    // Example tree
    Node* root = newNode(10);
    root->left = newNode(1);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->right = newNode(5);

    cout << "Maximum sum of non-adjacent nodes: " << getMaxSum(root) << endl;
    return 0;
}
/*
       10
      /  \
     1    2
    / \    \
   3   4    5
Maximum sum of non-adjacent nodes: 16
*/