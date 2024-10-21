#include<iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        // Base case: If root is NULL, return false
        if (!root) return false;

        // Check if it's a leaf node and targetSum matches the node's value
        if (!root->left && !root->right) return targetSum == root->val;

        // Recursively check the left and right subtrees with updated targetSum
        return hasPathSum(root->left, targetSum - root->val) || 
               hasPathSum(root->right, targetSum - root->val);
    }
};

// Helper function to create a binary tree for testing
TreeNode* createTree() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);
    return root;
}

int main() {
    // Create the binary tree
    TreeNode* root = createTree();

    // Example to check if a path sum exists
    Solution solution;
    int targetSum = 22;
    if (solution.hasPathSum(root, targetSum)) {
        cout << "Path with sum " << targetSum << " exists!" << endl;
    } else {
        cout << "No path with sum " << targetSum << " exists." << endl;
    }

    return 0;
}
/*      5
       / \
      4   8
     /   / \
    11  13  4
   /  \       \
  7    2       1

Path with sum 22 exists!
*/