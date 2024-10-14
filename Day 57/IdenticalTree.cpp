#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    bool isSameTree(TreeNode* p, TreeNode* q) {
        // if(p==NULL && q==NULL) return true; 
        // if(p!=NULL && q==NULL) return false; 
        // if(p==NULL && q!=NULL) return false; 

        // bool left = isSameTree(p->left, q->right); 
        // bool right = isSameTree(p->right, q->left); 

        // bool valCheck = p->val == q->val;

        // if(left && right && valCheck) return true;

        // return false;
        if(p==NULL && q==NULL) return true;
        if(p==NULL || q==NULL) return false;

        return (p->val == q->val) && isSameTree(p->left, q->right) && isSameTree(p->right, q->left);
    }

    bool isSymmetric(TreeNode* root) {
        return isSameTree(root->left , root->right);
    }
};
int main() {
    // Create a sample tree: 
    //     1
    //    / \
    //   2   2
    //  / \ / \
    // 3  4 4  3
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    Solution solution;
    bool result = solution.isSymmetric(root);
    if(result) {
        std::cout << "The tree is symmetric." << std::endl;
    } else {
        std::cout << "The tree is not symmetric." << std::endl;
    }

    // Clean up the allocated memory
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}