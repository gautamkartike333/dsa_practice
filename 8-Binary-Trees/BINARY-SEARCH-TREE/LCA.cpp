Ques Link :- "https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/"

HINT :-
1 - agar dono nodes opposite direction me lie kar rahe hain root ke , then current root is the answer 
2 - SAME direction me hain toh or aandar chale jao.







































CODE-
class Solution {
    public:
        TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q){
            if(root==NULL)return NULL;
            
            if((p->val <= root->val && q->val >= root->val) ||
              (p->val >= root->val && q->val <= root->val))
              {return root;}
            else if(p->val < root->val && q->val < root->val)
            {
            TreeNode* x=solve(root->left,p,q);
            if(x!=NULL)return x;
            }
            else if(p->val > root->val && q->val > root->val)
            {
            TreeNode* x=solve(root->right,p,q);
            if(x!=NULL)return x;
            }
            return NULL;
        }
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            return solve(root,p,q);
        }
    };