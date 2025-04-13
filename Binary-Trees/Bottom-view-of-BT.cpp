Ques Link : No ques link other than TUF+

But for reference try to code by yourself then check thge answer code here ="https://leetcode.com/discuss/post/1779760/bottom-view-in-binary-tree-c-easy-code-b-eazy/"




Hint :- same as top view

































CODE-
class Solution {
    public:
      vector <int> bottomView(TreeNode *root){
         vector<int>ans;
          if(root== NULL)return ans;
          map<int,TreeNode*>mapp;
          queue<pair<TreeNode*,int>>q;
          q.push({root,0});
          // int minix = INT_MAX,maxix=INT_MIN;
  
          while(!q.empty()){
              TreeNode* node = q.front().first;
              int x = q.front().second;
              q.pop();
  
              mapp[x] = node;
  
              if(node->left){q.push({node->left,x-1});}
              if(node->right){q.push({node->right,x+1});}
  
          }
         
          for(auto it : mapp){
              ans.push_back(it.second->data);
          }
          
          return ans;
  
      }
};