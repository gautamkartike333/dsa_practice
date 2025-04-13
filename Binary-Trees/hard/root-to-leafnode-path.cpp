Ques Link : "https://leetcode.com/problems/binary-tree-paths/description/"



Hint :-
jab leaf node pe pahucho toh push kardo ans vector me





































CODE:
class Solution {
    public:
        void solve(TreeNode* root , vector<string>&ans,string temp){
                if(root==NULL)return ;
                if(root->left==NULL && root->right==NULL){
                    temp += to_string(root->val);
                    ans.push_back(temp);return ;
                    }
                temp += to_string(root->val);
    
                solve(root->left,ans ,temp + "->");
                solve(root->right,ans,temp + "->");
    
            }
        vector<string> binaryTreePaths(TreeNode* root) {
                vector<string> ans;
                string temp="";
                solve(root,ans,temp);
                return ans;
        }
};