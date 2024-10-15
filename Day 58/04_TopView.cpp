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

vector<int> topView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    map<int, int> mp;
    queue<pair<Node *, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();
        Node *frontNode = temp.first;
        int hd = temp.second;

        // Mainting 1 to 1 mapping
        if (mp.find(hd) == mp.end()) // if hd not in mp , then it equals to mp.end
            mp[hd] = frontNode->data;

        if (frontNode->left)
            q.push(make_pair(frontNode->left, hd - 1));
        if (frontNode->right)
            q.push(make_pair(frontNode->right, hd + 1));
    }
    for (auto i : mp)
    {
        ans.push_back(i.second);
    }
    return ans;
}

int main()
{
    Node *root = NULL;
    cout << "Enter the tree: ";
    root = buildTree(root);

    vector<int> ans = topView(root);
    cout << "Top view : ";
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    /*
           1
         /   \
       2       3
      /  \    /  \
     4    5  6    7
    Input : 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
    Top view: 4 2 1 3 7
    */

    return 0;
}