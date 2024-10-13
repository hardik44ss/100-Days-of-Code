#include<bits/stdc++.h>
using namespace std;
#define NULL nullptr

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int x) {
            data = x;
            left = NULL;
            right = NULL;
        }
};

Node* buildTree(Node* root){
    int data ; 
    cin>>data;
    root = new Node(data);
    if(root->data == -1){
        return NULL;
    }
    root->left = buildTree(root->left);
    root->right = buildTree(root->right);

    return root;
}

void reversePrint(Node* root ) {
    vector<int> ans;
    if(!root) return ;

    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()){
        Node* temp = q.front();
        ans.push_back(temp->data);
        if(temp->right) q.push(temp->right);
        if(temp->left) q.push(temp->left);

        q.pop();
    }
    for(int i= ans.size()-1; i>=0; i--) cout<<ans[i]<<" ";
}
        

int main () 
{
    Node* root = NULL;
    root = buildTree(root);
    //Input : 1 3 7 -1 -1 10 -1 -1 5 11 -1 -1 -1

    reversePrint(root);
   
    
    return 0;
}