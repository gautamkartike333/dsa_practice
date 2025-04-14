Ques Link :- "https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/"



Hint :-
1 - jaha p, q me se koi ek bhi mil jaaye wahi se use return karna chalu kardo otherwise return nullptr
2 - if both left , right recursive calls doesnt returns NULL then that is the root which is our answer 

































CODE:-
class Solution {
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            if(root==NULL || root==p || root==q)return root;
    
            auto a = lowestCommonAncestor(root->left, p,q);
            auto b = lowestCommonAncestor(root->right,p,q);
            if(a!=NULL && b!=NULL)return root;
            if(a==NULL && b!=NULL)return b;
            else if(a!=NULL && b==NULL)return a;
    
            return NULL;
        }
};