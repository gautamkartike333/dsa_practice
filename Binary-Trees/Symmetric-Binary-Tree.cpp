Ques Link : "https://leetcode.com/problems/symmetric-tree/description/"


Hint 
1- har ek node pe jaake ke dekh lo ki barabar hai ki nahi
































CODE-
class Solution {
    public:
        bool solve(TreeNode* t1 , TreeNode* t2){
            if(t1==NULL || t2==NULL)return t1==t2;
            else if(t1->val != t2->val)return false;
    
            bool a = solve(t1->left,t2->right);
            bool b = solve(t1->right,t2->left);
    
            if(a==false || b==false)return false;
            return true;
        }
        bool isSymmetric(TreeNode* root) {
            if(root==NULL)return true;
            return solve(root->left,root->right);
        }
};