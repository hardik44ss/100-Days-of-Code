#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

Node *buildTree(Node *root)
{
    int data;
    cin >> data;
    root = new Node(data);
    if (root->data == -1)
    {
        return NULL;
    }
    root->left = buildTree(root->left);
    root->right = buildTree(root->right);

    return root;
}

void lView(Node *root, vector<int> &ans, int level)
{
    if (root == NULL)
        return;

    // Check new level , put data
    if (level == ans.size())
        ans.push_back(root->data);

    lView(root->left, ans, level + 1);
    lView(root->right, ans, level + 1);
}
vector<int> leftView(Node *root)
{
    vector<int> ans;
    lView(root, ans, 0);
    return ans;
}

int main()
{
    Node *root = NULL;
    cout<<"Enter tree: ";
    root = buildTree(root);

    vector<int> ans = leftView(root);
    cout<<"Left View: ";
    for (auto i : ans)
    {
        cout << i << " ";
    }

    /*
         1
       /   \
     2      3
   /   \   /  \
  4     5 6    7
   \
     8
    Input: 1 2 4 -1 8 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
    Output: [1, 2, 4, 8]
    */

    return 0;
}