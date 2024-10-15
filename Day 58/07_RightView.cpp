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

    void rView(Node* root , vector<int> &ans, int level){
        if(root==NULL) return ;
        
        //Check new level , put data 
        if(level ==ans.size()) ans.push_back(root->data);
        
        rView(root->right , ans,level+1);
        rView(root->left , ans,level+1);
    }
    vector<int> rightView(Node *root)
    {
       vector<int> ans;
       rView(root,ans,0);
       return ans;
    }

int main () 
{
    Node* root = NULL;
    cout<<"Enter tree: ";
    root = buildTree(root);

    vector<int> ans = rightView(root);
    cout<<"Right View: ";
    for(auto i: ans){
        cout<<i<<" ";
    }
    cout<<endl;
    
/*
     10
    /   \
  20     30
 /   \
40  60 
Input: 10 20 40 -1 -1 60 -1 -1 30 -1 -1
Output: 10 30 60
*/

    return 0;
}