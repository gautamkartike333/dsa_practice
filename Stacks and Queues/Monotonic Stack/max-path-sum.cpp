Ques Link: "https://leetcode.com/problems/binary-tree-maximum-path-sum/description/"



hint : same logic as height or diameter of tree -> bas usme kuch modifications karne hain.






























CODE:- 

class Solution {
    public:
        int solve(TreeNode* root,int& maxsum){
            if(root==NULL)return 0;
    
            int left =  max(0,solve(root->left,maxsum));
            int right = max(0,solve(root->right,maxsum));
           
            maxsum = max(maxsum,(left+right+(root->val)));
    
            return (max(left,right)+(root->val));
        }
        int maxPathSum(TreeNode* root) {
            int maxsum=INT_MIN;
            solve(root,maxsum);
            return maxsum;
        }
    };