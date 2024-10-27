#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};


// Converting BST into Doubly Linked List (DLL)
void convertintoDLL(TreeNode* root, TreeNode*& head) {
    if (!root) return;

    // Convert right subtree first
    convertintoDLL(root->right, head);

    // Connect current root to DLL
    root->right = head;
    if (head) head->left = root;
    head = root;

    // Convert left subtree
    convertintoDLL(root->left, head);
}

// Merging two sorted doubly linked lists
TreeNode* mergeLL(TreeNode* head1, TreeNode* head2) {
    TreeNode* head = nullptr;
    TreeNode* tail = nullptr;

    // Merge until one list is exhausted
    while (head1 && head2) {
        TreeNode* &nextNode = (head1->data < head2->data) ? head1 : head2;

        if (!head) {
            head = tail = nextNode;
        } else {
            tail->right = nextNode;
            nextNode->left = tail;
            tail = nextNode;
        }

        nextNode = nextNode->right;
    }

    // Attach remaining nodes if any
    tail->right = head1 ? head1 : head2;
    if (tail->right) tail->right->left = tail;

    return head;
}

// Counting the nodes in DLL
int countNode(TreeNode* head) {
    int cnt = 0;
    while (head) {
        cnt++;
        head = head->right;
    }
    return cnt;
}

// Convert DLL to Balanced BST
TreeNode* convertLLtoBST(TreeNode*& head, int n) {
    if (n <= 0 || !head) return nullptr;

    // Left subtree
    TreeNode* left = convertLLtoBST(head, n / 2);

    // Root node is current head
    TreeNode* root = head;
    root->left = left;

    // Advance head for right subtree
    head = head->right;

    // Right subtree
    root->right = convertLLtoBST(head, n - n / 2 - 1);
    return root;
}

// In-order traversal to store BST nodes in sorted order
void inOrder(vector<int> &ans, TreeNode *head) {
    if (head == nullptr)
        return;

    inOrder(ans, head->left);
    ans.push_back(head->data);
    inOrder(ans, head->right);
}

// Merge two BSTs and return sorted array of elements
vector<int> mergeBST(TreeNode *root1, TreeNode *root2) {
    // Convert BSTs to DLLs
    TreeNode* head1 = nullptr;
    convertintoDLL(root1, head1);
    if (head1) head1->left = nullptr;

    TreeNode* head2 = nullptr;
    convertintoDLL(root2, head2);
    if (head2) head2->left = nullptr;

    // Merge the two sorted DLLs
    TreeNode* mergedHead = mergeLL(head1, head2);

    // Convert merged DLL back to a balanced BST
    int n = countNode(mergedHead);
    TreeNode* bstRoot = convertLLtoBST(mergedHead, n);

    // Store the merged BST elements in sorted order
    vector<int> ans;
    inOrder(ans, bstRoot);
    return ans;
}

int main() {
    // Sample BSTs for testing
    TreeNode* root1 = new TreeNode(10);
    root1->left = new TreeNode(5);
    root1->right = new TreeNode(15);

    TreeNode* root2 = new TreeNode(12);
    root2->left = new TreeNode(7);
    root2->right = new TreeNode(20);

    // Merge BSTs and print the sorted order
    vector<int> result = mergeBST(root1, root2);
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
/*
Input Binary Tree 1 (root1):
     10
    /  \
   5    15

Input Binary Tree 2 (root2):
     12
    /  \
   7    20

Expected Merged Binary Tree (BST):
        10
       /   \
      7     15
     / \      \
    5   12     20
*/
