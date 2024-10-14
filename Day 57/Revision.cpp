//Balanced Tree
    pair<bool, int> isBalancedFast(Node* root) {
                // base case
        if(root == NULL)
        {
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }
        
        pair<int,int> left = isBalancedFast(root->left);
        pair<int,int> right = isBalancedFast(root->right);
        
        
        bool leftAns = left.first;
        bool rightAns = right.first;
        
        bool diff = abs (left.second - right.second ) <=1;
        
        pair<bool,int> ans;
        ans.second = max(left.second, right.second) + 1;
        
        if(leftAns && rightAns && diff) {
           ans.first = true;
        }
        else
        {
            ans.first = false;
        }
        return ans;
    }
    bool isBalanced(Node *root)
    {
        return isBalancedFast(root).first;
    }
    // bool isBalanced(Node *root)
    // {
    //     // Brute force approach : O(n^2)
    //     // if(root == NULL) return true;
        
    //     // bool left = isBalanced(root->left);
    //     // bool right = isBalanced(root->right);
        
    //     // bool diff = abs(height(root->left) - height(root->right)) <=1;
    //     // if(left && right && diff) return true;
    //     // return false;
        
    //     //Optimised approach : O(n)
    // }


//Identical Tree or not
    bool isIdentical(Node *r1, Node *r2)
    {
        if(r1==NULL && r2==NULL) return true;
        if(r1!=NULL && r2==NULL) return false;
        if(r1==NULL && r2!=NULL) return false;
        
        bool left = isIdentical(r1->left , r2->left);
        bool rightt = isIdentical(r1->right , r2->right);
        
        bool val = r1->data == r2->data ;
        
        if(left && rightt && val) return true;
        
        return false;
    }

//Sum Tree or not
        pair<bool , int> checkSum (Node* root ) {
        if(root==NULL) {
            pair <bool , int> p = make_pair(true, 0);
            return p;
        }
        
        if(root->left == NULL && root->right==NULL){
            pair<bool ,int> p = make_pair(true, root->data);
            return p;
        }
        
        pair<bool,int> left = checkSum(root->left); 
        pair<bool,int> right = checkSum(root->right); 
        
        bool leftAns = left.first;
        bool rightAns = right.first;
        bool check = root->data == left.second + right.second;
        
        pair<bool ,int> ans;
        if(leftAns && rightAns && check){
            ans.first= true;
            ans.second = 2*root->data;
        }else{
            ans.first = false;
            
        }
        return ans;
    }

    bool isSumTree(Node* root) {
        // Your code here
        return checkSum(root).first;
    }