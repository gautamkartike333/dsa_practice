Ques Link :"https://leetcode.com/problems/insert-into-a-binary-search-tree/description/"





HINT:- Just find position where to insert the node then insert it


















CODE:-

class Solution {
    public:
        void solve(TreeNode* root, int key){
    
            if(key < root->val){
                if(root->left==NULL){
                TreeNode* x = new TreeNode(key);
                root->left=x;}
                else solve(root->left,key);
            }
            else {
                if(root->right ==NULL){
                    TreeNode* x = new TreeNode(key);
                    root->right=x;
                    }
                else solve(root->right,key);
                
            }
    
    
        }
        TreeNode* insertIntoBST(TreeNode* root, int val) {
            if(root==NULL){
               TreeNode* x = new TreeNode(val);
               return x; 
            }
    
            solve(root,val);
            return root;
        }
    };