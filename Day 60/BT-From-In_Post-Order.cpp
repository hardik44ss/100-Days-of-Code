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


Node* solve(vector<int> in , vector<int> post, int &index, int inStart, int inEnd, int n, map<int, int> &nodeToIndex) {
    
    if (index <0 || inStart > inEnd) return NULL;

    
    int element = post[index--];
    Node* curr = new Node(element);

    int pos = nodeToIndex[element];

    // Right subtree is constructed first as postorder traversal is left-right-root
    curr->right = solve(in, post, index, pos + 1, inEnd, n, nodeToIndex);
    curr->left = solve(in, post, index, inStart, pos - 1, n, nodeToIndex);

    return curr;
}

Node* buildTree(vector<int> inorder, vector<int> postorder) {
      
    map<int, int> nodeToIndex;
    int n = inorder.size();
    // Fill the map with inorder element indices
    for (int i = 0; i < n; i++) {
        nodeToIndex[inorder[i]] = i;
    }

    int index = n-1;

    // Recursively build the tree
    Node* ans = solve(inorder, postorder, index, 0, n - 1, n, nodeToIndex);
    return ans;
}
void printPreorder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

// Example usage
int main() {
    vector<int> inorder = {4, 8, 2, 5, 1, 6, 3, 7};
    vector<int> postorder = {8, 4, 5, 2, 6, 7, 3, 1};

    Node* root = buildTree(inorder, postorder);

    cout << "Preorder traversal of the constructed tree: ";
    printPreorder(root);
    cout << endl;
/*
         1
       /   \
     2      3
   /  \    /  \
  4   5   6    7
   \
    8
*/

    return 0;
}
