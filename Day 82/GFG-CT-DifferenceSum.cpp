//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* inputTree() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for (int i = 0; i < n; i++)
        cin >> ar[i];

    if (ar.empty())
        return NULL;
    Node* root = new Node(ar[0]);
    queue<Node*> q;
    q.push(root);
    int i = 1;
    while (i < n) {
        Node* curr = q.front();
        q.pop();
        if (i < n) {
            curr->left = new Node(ar[i++]);
            q.push(curr->left);
        }
        if (i < n) {
            curr->right = new Node(ar[i++]);
            q.push(curr->right);
        }
    }
    return root;
}


// } Driver Code Ends
/*

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void levelOrderTraversal(Node* root,vector<int> &arr){
        if (!root) return;
        
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();

            arr.push_back(temp->data);

            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
    }
    int differenceSum(Node* root1, Node* root2) {
        // code here
        vector<int> arr1 , arr2;
        levelOrderTraversal(root1,arr1);
        levelOrderTraversal(root2,arr2);
        
        int n1 = arr1.size();
        int n2 = arr2.size();
        int i = 0;
        int sum = 0 ;
        while(i<n1 && i < n2){
            sum += abs(arr1[i] - arr2[i]);
            i++;
        }
        while(i<n1) sum+=abs(arr1[i++]);
        while(i<n2) sum+=abs(arr2[i++]);
        return sum ;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        Node* root1 = inputTree();

        Node* root2 = inputTree();

        Solution obj;
        int res = obj.differenceSum(root1, root2);

        cout << res << endl;
    }
}

// } Driver Code Ends