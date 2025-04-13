Ques Link : "https://leetcode.com/problems/binary-tree-right-side-view/description/"

Hint :- 
1-Level order traversal
2-Har ek level ke end me vector me push kardo value 




































CODE-
class Solution {
    public:
        vector<int> rightSideView(TreeNode* root) {
            queue<TreeNode*>q;
            vector<int>ans;
            if(root==NULL)return ans;
            q.push(root);
            while(!q.empty()){
                int n = q.size();
                TreeNode* fs;
                TreeNode* node = q.front();
                for(int i=0;i<n;i++){
                    node = q.front();q.pop();
                    
                    if(node->left )q.push(node->left);
                    if(node->right)q.push(node->right);
                }
                ans.push_back(node->val);
            }
            return ans;
        }
};