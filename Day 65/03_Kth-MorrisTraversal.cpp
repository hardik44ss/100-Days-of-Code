#include <iostream>
using namespace std;

// Definition of the binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to find the Kth smallest element using Morris Traversal
int kthSmallest(TreeNode* root, int k) {
    TreeNode* curr = root;
    int count = 0; // To count the number of processed nodes
    int result = -1; // To store the Kth smallest value

    while (curr != NULL) {
        if (curr->left == NULL) {
            // Visit this node
            count++;
            if (count == k)
                result = curr->val;
            
            // Move to the right child
            curr = curr->right;
        } else {
            // Find the inorder predecessor of curr
            TreeNode* pred = curr->left;
            while (pred->right != NULL && pred->right != curr)
                pred = pred->right;
            
            // Create a thread (temporary link) from predecessor to curr
            if (pred->right == NULL) {
                pred->right = curr;
                curr = curr->left;
            } else {
                // If the thread already exists, remove it
                pred->right = NULL;
                
                // Visit this node
                count++;
                if (count == k)
                    result = curr->val;
                
                // Move to the right child
                curr = curr->right;
            }
        }
    }
    
    return result; // Return the Kth smallest value
}

// Helper function to insert nodes in the BST
TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    
    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    
    return root;
}

int main() {
    TreeNode* root = NULL;
    
    // Example: inserting nodes in the BST
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 6);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 1);
    
    int k = 3; // Find the 3rd smallest element
    cout << "The " << k << "rd smallest element is " << kthSmallest(root, k) << endl;

    return 0;
}
//         5
//        / \
//       3   6
//      / \
//     2   4
//    /
//   1
