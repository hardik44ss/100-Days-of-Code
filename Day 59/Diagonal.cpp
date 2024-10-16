#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to perform diagonal traversal of binary tree
void diagonalTraversal(TreeNode* root) {
    if (!root)
        return;

    // Create a map to store diagonal elements
    map<int, vector<int>> diagonalMap;

    // Queue to store tree nodes for level order traversal
    queue<pair<TreeNode*, int>> q;

    // Start from root, and its diagonal distance is 0
    q.push({root, 0});

    while (!q.empty()) {
        // Get the front node and diagonal distance
        TreeNode* node = q.front().first;
        int diagonal = q.front().second;
        q.pop();

        // Add the current node to its diagonal in the map
        diagonalMap[diagonal].push_back(node->val);

        // If there is a left child, it belongs to the next diagonal
        if (node->left)
            q.push({node->left, diagonal + 1});

        // Right child stays on the same diagonal
        if (node->right)
            q.push({node->right, diagonal});
    }

    // Print the diagonal traversal from the map
    for (auto it : diagonalMap) {
        for (int x : it.second) {
            cout << x << " ";
        }
        cout << endl;
    }
}

// Function to insert a new node in the binary tree
TreeNode* insertNode(TreeNode* root, int val) {
    if (!root)
        return new TreeNode(val);

    if (val < root->val)
        root->left = insertNode(root->left, val);
    else
        root->right = insertNode(root->right, val);

    return root;
}

int main() {
    // Create a binary tree
    TreeNode* root = NULL;
    root = insertNode(root, 8);
    root = insertNode(root, 3);
    root = insertNode(root, 10);
    root = insertNode(root, 1);
    root = insertNode(root, 6);
    root = insertNode(root, 14);
    root = insertNode(root, 4);
    root = insertNode(root, 7);
    root = insertNode(root, 13);

    // Perform diagonal traversal
    cout << "Diagonal Traversal of Binary Tree:" << endl;
    diagonalTraversal(root);

    /*
          8
         / \
        3   10
       / \    \
      1   6    14
         / \   /
        4   7 13
    Diagonal:8 10 14 
             3 6 7 13 
             1 4 
    */

    return 0;
}
