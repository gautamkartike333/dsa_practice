Ques Link : "https://leetcode.com/problems/same-tree/description/"

HINT :- Jaha identical na ho waha se false return kardo .







































CODE:-

class Solution {
    public:
        bool solve(TreeNode* p,TreeNode* q){
            if(p==NULL && q==NULL)return true;
            else if(p==NULL && q!=NULL)return false;
            else if(p!=NULL && q==NULL)return false;
            else if(p->val != q->val)return false;
    
            bool l = solve(p->left,q->left);
            bool r = solve(p->right,q->right);
            if(l==false || r==false)return false;
    
            // if(p->val==q->val)
            return true;
    
        }
        bool isSameTree(TreeNode* p, TreeNode* q) {
            return solve(p,q);
        }
};