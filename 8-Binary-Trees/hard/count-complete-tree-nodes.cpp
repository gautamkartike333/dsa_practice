Ques Link : "https://leetcode.com/problems/count-complete-tree-nodes/description/"

HINT -
1 - dhyan se ques padho ek baar mere kehne se please
2 - haan toh dobara ques padha ? usme pata padi hogi ki complete tree ke no. of nodes batane hain , mtlb last level tak completely filled as fas as left
    mtlb ki leftheight and r8height ye compulsory nahi h ki ye dono equal ho , -> agar equal hui toh seedhe seedhe 2 ki power h -1 answer hai
3 -  lh!=rh hai toh kya karna hai , are dobara wohi fxn call kardo taki aage ki root->left ki left and r8 height barabar hui toh so-on













































CODE:-
class Solution {
    public:
        int findlht(TreeNode* root){
    
            int ct=0;
            while(root){
                ct++;
                root = root->left;
            }
            return ct;
        }
        int findrht(TreeNode* root){
    
            int ct=0;
            while(root){
                ct++;
                root = root->right;
            }
            return ct;
        }
        int solve(TreeNode* root){
            if(root==NULL)return 0;
    
            int lh = findlht(root);
            int rh = findrht(root);
    
            if(lh==rh){
                return (1<<lh)-1;
            }
    
            return solve(root->left)+solve(root->right)+1;
        }
        int countNodes(TreeNode* root) {
            
           return solve(root);
    
        }
    };