#include <iostream>
#include <algorithm>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;  // Base case: empty tree
        
        // If one of the children is null, we ignore that subtree
        if (root->left == nullptr) return 1 + minDepth(root->right);
        if (root->right == nullptr) return 1 + minDepth(root->left);
        
        // If both children are non-null, we take the minimum of the two
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};

int main() {
    // Create a sample tree: 
    //     3
    //    / \
    //   9  20
    //     /  \
    //    15   7
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    int depth = sol.minDepth(root);
    std::cout << "Minimum depth of the binary tree is: " << depth << std::endl;

    // Clean up memory
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}