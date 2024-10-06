#include<iostream>
#include<queue>
using namespace std;

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
    cout<<"Enter data : ";
    cin>>data;
    root = new Node(data);
    if(root->data == -1){
        return NULL;
    }
    //Recursilvely inserting value of left and right child
    cout<<"Enter left child of "<<root->data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter right child of "<<root->data<<endl;
    root->right = buildTree(root->right);

    return root;
}

//Printing BT using level order traversal
void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout<<temp->data<<" ";
            if(temp->left) 
                q.push(temp->left);
            if(temp->right) 
                q.push(temp->right);
        }
    }
}

void inOrder(Node* root){
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void preOrder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node* root){
    if(root==NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

int main () 
{
    Node* root = NULL;
    root = buildTree(root);
    //Input : 1 3 7 -1 -1 10 -1 -1 5 11 -1 -1 -1
    levelOrderTraversal(root);

    cout<<"Inorder : ";
    inOrder(root);
    cout<<endl;

    cout<<"Preorder : ";
    preOrder(root);
    cout<<endl;

    cout<<"Postorder : ";
    postOrder(root);
    cout<<endl;
    
    return 0;
}