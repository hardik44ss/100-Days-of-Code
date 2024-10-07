//Height : longest path between Root node and Leaf node.
#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

int height(Node* root)
{
    if(root == NULL)
        return 0;
    int lheight = height(root->left);
    int rheight = height(root->right);
    return max(lheight, rheight) + 1;
}
//TIme : O(n)  , Space : O(h)  height of the tree.

int main () 
{
    Node* root = new Node();
    root->data = 1;
    root->left = new Node();
    root->left->data = 2;
    root->right = new Node();
    root->right->data = 3;  
    root->left->left = new Node();
    root->left->left->data = 4;
    root->left->right = new Node();
    root->left->right->data = 5;
    root->right->left = new Node();
    root->right->left->data = 6;
    root->right->right = new Node();
    root->right->right->data = 7;
    root->right->right->right = new Node();
    root->right->right->right->data = 8;

    cout << "Height of the tree is : " << height(root) << endl;
    return 0;
}
/*
                                  1
                                /   \
                               2     3
                             /  \   /  
                            4    5 6
                                  /
                                 7
                                  \
                                   8
*/