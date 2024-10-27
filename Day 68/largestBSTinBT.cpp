#include <iostream>
#include <climits>
using namespace std;

/*
    Following is Binary Tree Node structure:
*/
class TreeNode {
public:
    int data;
    TreeNode *left, *right;

    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
};

/*
    Auxiliary class to store details for each node during traversal.
*/
class Info {
public:
    int mini;
    int maxi;
    bool isBST;
    int size;

    Info(int minValue, int maxValue, bool isBst, int sz) 
        : mini(minValue), maxi(maxValue), isBST(isBst), size(sz) {}

    // Default constructor
    Info() : mini(INT_MAX), maxi(INT_MIN), isBST(true), size(0) {}
};

/*
    Function to recursively solve each subtree and calculate the largest BST.
*/
Info solve(TreeNode* root, int &ans) {
    if (root == NULL)
        return Info(INT_MAX, INT_MIN, true, 0);
    
    Info left = solve(root->left, ans); 
    Info right = solve(root->right, ans); 

    Info currNode;
    currNode.size = left.size + right.size + 1;
    currNode.maxi = max(root->data, right.maxi);
    currNode.mini = min(root->data, left.mini);

    if (left.isBST && right.isBST && (root->data > left.maxi) && (root->data < right.mini)) {
        currNode.isBST = true;
        ans = max(ans, currNode.size);
    } else {
        currNode.isBST = false;
    }

    return currNode;
}

int largestBST(TreeNode *root) {
    int maxSize = 0;
    solve(root, maxSize);
    return maxSize;
}

/*
    Utility function to create nodes
*/
TreeNode* createNode(int data) {
    return new TreeNode(data);
}

int main() {
    /*
        Example Binary Tree:
        
                    25
                   /  \
                  10   20
                 / \    \
                5  12    30
                  / 
                 11

        In this tree, the largest BST subtree is:

                  10
                 /  \
                5    12
                   /
                  11

        Expected Output: 4 (as the largest BST has 4 nodes)
    */
    
    TreeNode *root = createNode(25);
    root->left = createNode(10);
    root->right = createNode(20);
    root->left->left = createNode(5);
    root->left->right = createNode(12);
    root->left->right->left = createNode(11);
    root->right->right = createNode(30);

    int largestBSTSize = largestBST(root);
    cout << "Largest BST size in the given binary tree is: " << largestBSTSize << endl;

    return 0;
}
