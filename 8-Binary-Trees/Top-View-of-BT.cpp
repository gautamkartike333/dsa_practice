Ques Link: "https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1"




Hint :- 
1 - Level Order traversal.
2 - mapp me push kardo jo naya element mile uss vertical line par.
3 - use queue to trace level order traversal.
































CODE:-
class Solution {
    public:
      // Function to return a list of nodes visible from the top view
      // from left to right in Binary Tree.
      vector<int> topView(Node *root) {
          // code here
       vector<int>ans;
          if(root== NULL)return ans;
          map<int,Node*>mapp;
          queue<pair<Node*,int>>q;
          q.push({root,0});
          int minix = INT_MAX,maxix=INT_MIN;
          while(!q.empty()){
              Node* node = q.front().first;
              int x = q.front().second;
              q.pop();
  
              if(mapp.find(x) != mapp.end()){}
              else {mapp[x] = node;
                    minix = min(minix,x);
                    maxix = max(maxix,x);
              }
              
              if(node->left){q.push({node->left,x-1});}
              if(node->right){q.push({node->right,x+1});}
  
          }
         
          for(auto it : mapp){
              ans.push_back(it.second->data);
          }
          
          return ans;
      }
  };