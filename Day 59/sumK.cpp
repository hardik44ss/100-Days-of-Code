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

// Helper function to find paths that sum to k
void solve(Node* root, int k, int &count, vector<int> &ans) {
    // Base case: if root is NULL, return
    if (root == NULL) return;

    // Add the current node's data to the path
    ans.push_back(root->data);

    // Recur for left and right children
    solve(root->left, k, count, ans);
    solve(root->right, k, count, ans);

    // Check if any sub-path ending at this node sums up to k
    int size = ans.size() - 1;
    int sum = 0;
    for (int i = size; i >= 0; i--) {
        sum += ans[i];
        if (sum == k) count++;  // If a sub-path with sum k is found, increment count
    }

    // Remove the current node's data from the path
    ans.pop_back();
}

// Function to find the number of paths in the tree that sum to k
int sumK(Node *root, int k) {
    int count = 0;           // Counter to track the number of valid paths
    vector<int> ans;         // Vector to store the current path
    solve(root, k, count, ans);  // Call the helper function
    return count;            // Return the final count
}

int main() {
    // Create the binary tree
    Node* root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(-1);
    root->left->left = new Node(2);
    root->left->right = new Node(1);
    root->left->right->left = new Node(1);
    root->right->left = new Node(4);
    root->right->right = new Node(5);
    root->right->left->left = new Node(1);
    root->right->left->right = new Node(2);

    int k = 5; // Target sum to find

    // Call the sumK function to get the count of paths summing to k
    cout << "Number of paths with sum " << k << " is: " << sumK(root, k) << endl;

    return 0;
}
/*
          1
         / \
        3  -1
       / \  / \
      2   1 4   5
         /   / \
        1   1   2
    Number of paths with sum 5 is: 4
*/