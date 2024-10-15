#include <bits/stdc++.h>
using namespace std;
#define NULL nullptr

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
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

void preOrderIterative(Node *root)
{
    stack<Node *> s;
    s.push(root);
    while (!s.empty())
    {
        Node *temp = s.top();
        cout << temp->data << " ";
        s.pop();
        if (temp->right)
            s.push(temp->right);
        if (temp->left)
            s.push(temp->left);
    }
}

vector<int> postOrder(Node *node)
{
    // code here
    vector<int> ans;
    stack<Node *> s;
    s.push(node);
    while (!s.empty())
    {
        Node *temp = s.top();
        ans.push_back(temp->data);
        s.pop();
        if (temp->left)
            s.push(temp->left);
        if (temp->right)
            s.push(temp->right);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

vector<int> inOrder(Node *root)
{
    // code here
    vector<int> ans;
    stack<Node *> s;
    stack<bool> visited;
    s.push(root);
    visited.push(0);
    while (!s.empty())
    {
        Node *temp = s.top();
        s.pop();
        bool flag = visited.top();
        visited.pop();
        if (flag == 0)
        {
            if (temp->right)
            {
                s.push(temp->right);
                visited.push(0);
            }
            s.push(temp);
            visited.push(1);
            if (temp->left)
            {
                s.push(temp->left);
                visited.push(0);
            }
        }
        else
        {
            ans.push_back(temp->data);
        }
    }
    return ans;
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    // Input : 1 3 7 -1 -1 10 -1 -1 5 11 -1 -1 -1

    reversePrint(root);

    return 0;
}