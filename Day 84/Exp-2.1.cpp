#include <iostream>

using namespace std;

// Define the structure of a tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Define the binary tree class
class BinaryTree {
public:
    Node* root;

    BinaryTree() : root(nullptr) {}

    // Pre-order traversal
    void preOrder(Node* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }

    // In-order traversal
    void inOrder(Node* node) {
        if (node == nullptr) return;
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }

    // Post-order traversal
    void postOrder(Node* node) {
        if (node == nullptr) return;
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }

    // Insert a node into the binary tree
    void insert(int val) {
        if (root == nullptr) {
            root = new Node(val);
        } else {
            insertNode(root, val);
        }
    }

private:
    // Helper function to insert nodes recursively
    void insertNode(Node* node, int val) {
        if (val < node->data) {
            if (node->left == nullptr) {
                node->left = new Node(val);
            } else {
                insertNode(node->left, val);
            }
        } else {
            if (node->right == nullptr) {
                node->right = new Node(val);
            } else {
                insertNode(node->right, val);
            }
        }
    }
};

int main() {
    BinaryTree tree;

    // Inserting values into the binary tree
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "Pre-order traversal: ";
    tree.preOrder(tree.root);
    cout << endl;

    cout << "In-order traversal: ";
    tree.inOrder(tree.root);
    cout << endl;

    cout << "Post-order traversal: ";
    tree.postOrder(tree.root);
    cout << endl;
 
    return 0;
}
/*
Pre-order traversal: 50 30 20 40 70 60 80 
In-order traversal: 20 30 40 50 60 70 80 
Post-order traversal: 20 40 30 60 80 70 50 
*/