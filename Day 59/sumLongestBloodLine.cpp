#include <iostream>
#include <climits> // For INT_MIN

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

// Function to solve the problem and find the sum of the longest path from root to leaf
void solve(Node* root, int sum, int &maxSum, int len, int &maxLen) {
    // Base case: if the node is NULL, check for max length and sum
    if(root == NULL) {
        if(len > maxLen) {
            maxLen = len;
            maxSum = sum;
        } 
        else if(len == maxLen) {
            maxSum = max(sum, maxSum); // If same length, take the maximum sum
        }
        return;
    }

    // Add the current node's data to the sum
    sum = sum + root->data;

    // Recur for left and right subtrees with updated length and sum
    solve(root->left, sum, maxSum, len + 1, maxLen);
    solve(root->right, sum, maxSum, len + 1, maxLen);
}

// Function to return the sum of the longest root to leaf path
int sumOfLongRootToLeafPath(Node *root) {
    int len = 0;       // Length of the current path
    int maxLen = 0;    // Max length of the path
    int sum = 0;       // Sum of the current path
    int maxSum = INT_MIN; // Maximum sum along the longest path

    // Solve the problem recursively
    solve(root, sum, maxSum, len, maxLen);

    return maxSum; // Return the maximum sum of the longest path
}

int main() {
    // Create the binary tree
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(60);
    root->right->right = new Node(50);
    root->right->left = new Node(90);
    root->right->left->left = new Node(70);
    /*
         10
        /  \
      20   30
     /  \   / \
    40  60 90  50
          /
         70
*/

    // Call the function and print the result
    cout << "Sum of the longest root-to-leaf path is: " << sumOfLongRootToLeafPath(root) << endl;

    return 0;
}
