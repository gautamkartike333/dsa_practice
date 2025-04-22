Ques Link - "https://leetcode.com/problems/validate-binary-search-tree/description/"




HINT :-
1 - Give limit to all the nodes , minnodeval and maxnodeval , if it lies beyond this range then return false;





























CODE:-

class Solution {
    public:
        bool solve(TreeNode* root, long long minval,long long maxval){
            if(root==NULL)return true;
    
            if(root->val >= maxval || root->val <= minval)return false;
    
            return solve(root->left,minval,root->val) && solve(root->right,root->val,maxval);
        }
    
        bool isValidBST(TreeNode* root) {
    
            return solve(root,LLONG_MIN,LLONG_MAX);
    
        }
    };