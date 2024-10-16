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

vector<int> zigZag(Node* root){
    vector<int> result;
    if(!root) return result;
    queue<Node*> q;
    q.push(root);

    bool leftToRight=true;
    while(!q.empty()){
        int size = q.size();
        vector<int> levelElements(size);

        for(int i = 0 ; i <size; i++){
            Node* frontNode = q.front();
            q.pop();

            int index = leftToRight ? i : size-i-1;
            levelElements[index] = frontNode->data;

            if(frontNode->left) q.push(frontNode->left);
            if(frontNode->right) q.push(frontNode->right);
        }

        leftToRight = !leftToRight;
        for(auto i : levelElements) result.push_back(i);
    }
    return result;
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
// Output: 1 3 2 4 5 6 7 9 8

    vector<int> boundaryTraversal = zigZag(root);

    cout << "Spiral Traversal : ";
    for (int i : boundaryTraversal) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}