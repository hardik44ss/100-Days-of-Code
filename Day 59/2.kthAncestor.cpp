#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Definition for a binary tree node.
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

Node *solve(Node *root, int &k, int node)
{
    // Base case
    if (root == NULL)
        return NULL;
    if (root->data == node)
        return root;

    Node *leftAns = solve(root->left, k, node);
    Node *rightAns = solve(root->right, k, node);

    if (leftAns != NULL && rightAns == NULL)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }
    if (leftAns == NULL && rightAns != NULL)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }
    return NULL;
}
int kthAncestor(Node *root, int k, int node)
{
    Node *ans = solve(root, k, node);
    if (root == NULL || ans->data == node)
    {
        return -1;
    }
    return ans->data;
}

int main()
{
    // Create the binary tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int node = 5, k = 2;
    cout << "The " << k << "th ancestor of node " << node << " is: " << kthAncestor(root, k, node) << endl;

    return 0;
}
/*
          1
         / \
        2   3
       / \  / \
      4   5 6  7

*/