#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> output;

vector<vector<int>> levelOrder(TreeNode *root)
{
    queue<TreeNode *> q;
    if (root)
    {
        q.push(root);
    }
    while (!q.empty())
    {
        int l = q.size();
        vector<int> temp;
        for (int i = 0; i < l; i++)
        {
            TreeNode *t = q.front();
            if (t->left)
                q.push(t->left);
            if (t->right)
                q.push(t->right);
            temp.push_back(t->val);
            q.pop();
        }
        output.push_back(temp);
    }

    return output;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<vector<int>> result = levelOrder(root);

    for (const auto &level : result)
    {
        for (int val : level)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    // Clean up memory
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root;

    return 0;
}