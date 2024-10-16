#include <iostream>
using namespace std;

// Definition of a node in the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to return the lowest common ancestor in a Binary Tree.
Node* lca(Node* root, int n1, int n2) {
    // Base case: If the root is NULL, return NULL
    if (root == NULL)
        return NULL;

    // If root matches either n1 or n2, return root
    if (root->data == n1 || root->data == n2)
        return root;

    // Recur for the left and right subtrees
    Node* leftAns = lca(root->left, n1, n2);
    Node* rightAns = lca(root->right, n1, n2);

    // If both sides return non-NULL, root is the LCA
    if (leftAns != NULL && rightAns != NULL)
        return root;

    // Otherwise, return the non-NULL side (either leftAns or rightAns)
    return (leftAns != NULL) ? leftAns : rightAns;
}

int main() {
    // Creating a sample binary tree
    Node* root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->right->left = new Node(0);
    root->right->right = new Node(8);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);

    // Example nodes n1 and n2
    int n1 = 5, n2 = 1;
    
    // Call the LCA function
    Node* ans = lca(root, n1, n2);

    // Print the result
    if (ans != NULL)
        cout << "LCA of " << n1 << " and " << n2 << " is: " << ans->data << endl;
    else
        cout << "LCA does not exist." << endl;

    return 0;
}
/*
          3
        /   \
       5     1
      / \   / \
     6   2 0   8
        / \
       7   4
    LCA of 5 and 1 is: 3

*/
