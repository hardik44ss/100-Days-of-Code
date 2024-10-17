#include <iostream>
#include <map>
#include <queue>
using namespace std;

// Node structure for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Function to create a mapping of nodes to their parent and return the target node
Node* createParentMapping(Node* root, int target, map<Node*, Node*> &nodeToParent) {
    Node* res = NULL;
    
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()) {
        Node* Front = q.front();
        q.pop();
        
        if(Front->data == target)
            res = Front;
        
        if(Front->left) {
            nodeToParent[Front->left] = Front;
            q.push(Front->left);
        }
        
        if(Front->right) {
            nodeToParent[Front->right] = Front;
            q.push(Front->right);
        }
    }
    return res;
}

// Function to calculate the minimum time to burn the tree
int burnTree(Node* root, map<Node*, Node*> &nodeToParent) {
    map<Node*, bool> visited;
    queue<Node*> q;
    
    q.push(root);
    visited[root] = true;
    
    int ans = 0;
    bool flag = 0;
    while(!q.empty()) {
        int size = q.size();
        flag = 0; // Reset flag for each level
        
        for(int i = 0; i < size; i++) {
            Node* front = q.front();
            q.pop();
            
            if(front->left && !visited[front->left]) {
                flag = 1;
                q.push(front->left);
                visited[front->left] = true;
            }
            
            if(front->right && !visited[front->right]) {
                flag = 1;
                q.push(front->right);
                visited[front->right] = true;
            }
            
            if(nodeToParent[front] && !visited[nodeToParent[front]]) {
                flag = 1;
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]] = true;
            }
        }
        
        // If flag is set, it means we processed a new level
        if(flag == 1) ans++;
    }
    return ans;
}

// Main function to find the minimum time to burn the tree from the target node
int minTime(Node* root, int target) {
    // 1. Create a node-to-parent mapping
    // 2. Find the target node
    // 3. Burn the tree in minimum time
    map<Node*, Node*> nodeToParent;
    Node* targetNode = createParentMapping(root, target, nodeToParent);
    int ans = burnTree(targetNode, nodeToParent);
    
    return ans;
}

// Helper function to create a binary tree for testing
Node* buildTree() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    return root;
}

// Driver code
int main() {
    Node* root = buildTree();
    int target = 5;
    
    cout << "Minimum time to burn the tree from target node " << target << " is: " << minTime(root, target) << endl;
    
    return 0;
}
/*        1
        /   \
       2     3
      / \   / \
     4   5 6   7

*/