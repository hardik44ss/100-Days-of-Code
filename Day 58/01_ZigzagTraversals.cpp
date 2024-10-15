#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
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

void traverseLeft(Node* root , vector<int> &ans){
        if(!root|| (!root->left && !root->right)) return;
            
        ans.push_back(root->data);
        
        if(root->left) traverseLeft(root->left ,ans);
        else traverseLeft(root->right ,ans);
    }
    
    void traverseLeaf(Node* root , vector<int> &ans){
        if(!root) return;
        
        if(!root->left  && !root->right) ans.push_back(root->data);
        
        traverseLeaf(root->left, ans);
        traverseLeaf(root->right, ans);
    }
    
    void traverseRight(Node* root , vector<int> &ans){
        if(!root || (!root->left && !root->right)) return;
            
        if(root->right) traverseRight(root->right ,ans);
        else traverseRight(root->left ,ans);
        
        ans.push_back(root->data);
    }
    
    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        if(!root) return ans;
        
        ans.push_back(root->data);
        traverseLeft(root->left,ans); 
        
        traverseLeaf(root->left,ans);
        traverseLeaf(root->right,ans);
        
        traverseRight(root->right,ans); 
        
        return ans;
    }

int main () 
{
    Node* root = NULL;
    cout << "Enter the nodes of the tree in pre-order fashion (use -1 for NULL nodes):" << endl;
    root = buildTree(root);
//         1 
//       /   \
//      2     3  
//     / \   / \ 
//    4   5 6   7
//       / \
//      8   9
// Input: 1 2 4 -1 -1 5 8 -1 -1 9 -1 -1 3 6 -1 -1 7 -1 -1
// Output: 1 2 4 8 9 6 7 3

    vector<int> boundaryTraversal = boundary(root);

    cout << "Boundary Traversal : ";
    for (int i : boundaryTraversal) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}