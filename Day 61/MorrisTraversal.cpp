#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void flatten(TreeNode* root) {

    TreeNode* curr = root;
    while(curr!=NULL){
        if(curr->left){
            TreeNode* pred = curr->left;
            while(pred->right){
                pred = pred->right;
            }

            pred->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr=curr->right;
    }
}
// Helper function to print the flattened tree
void printFlattenedTree(TreeNode* root) {
    TreeNode* curr = root;
    while (curr != NULL) {
        std::cout << curr->val << " ";
        curr = curr->right;
    }
    std::cout << std::endl;
}

// Main function to test the flatten function
int main() {
    // Create a sample tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    // Flatten the tree
    flatten(root);

    // Print the flattened tree
    printFlattenedTree(root);

    // Clean up memory
    delete root->right->right;
    delete root->right;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root;

    return 0;
}