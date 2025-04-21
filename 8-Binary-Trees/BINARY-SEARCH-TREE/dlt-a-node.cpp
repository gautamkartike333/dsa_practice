Ques Link : "https://leetcode.com/problems/delete-node-in-a-bst/description/"




HINT-
1 -  first find the node 
2 -  if it exists then dlt it










































CODE-
Striver code is more better in terms of beautifulness ans small.

my code-
class Solution {
    public:
        void solve(TreeNode* root, int key,TreeNode* curr,TreeNode* x){
            if(x==NULL)return;
    
            if(x->val == key){
                if(curr->left == x){
                    if(x->left==NULL){
                        curr->left = x->right;
                        return;
                    }
                    else if(x->right == NULL){
                        curr->left = x->left;
                        return;
                    }
                    else{
                        curr->left = x->right;
                        TreeNode* y = curr->left;
                        while(y->left!=NULL)y=y->left;
                        y->left = x->left;
                        return;
                    }
                }
                else if(curr->right ==x){
                    if(x->left==NULL){
                        curr->right = x->right;
                        return;
                    }
                    else if(x->right == NULL){
                        curr->right = x->left;
                        return;
                    }
                    else{
                        curr->right = x->left;
                        TreeNode* y = curr->right;
                        while(y->right!=NULL)y=y->right;
                        y->right = x->right;
                        return;
                    }
                }
            }
            else {
                if(key < x->val){
                    curr = x;
                    x = x->left;
                    solve(root,key,curr,x);
                }
                else {
                    curr=x;
                    x=x->right;
                    solve(root,key,curr,x);
                }
            }
    
    
        }
        TreeNode* deleteNode(TreeNode* root, int key) {
            if(root==NULL)return NULL;
            if(root->val == key){
                if(root->left==NULL)return root->right;
                if(root->right==NULL)return root->left;
                TreeNode* newroot = root->left;
                TreeNode* x = newroot;
                while(x->right != NULL)x = x->right;
                x->right = root->right;
                return newroot;
            }
            TreeNode* curr = root;
            TreeNode* x = root;
            if(key < root->val) x = root->left;
            else x = root->right;
            // findroot(root,key,x,curr);
            solve(root,key,curr,x);
            return root;
        }
    };