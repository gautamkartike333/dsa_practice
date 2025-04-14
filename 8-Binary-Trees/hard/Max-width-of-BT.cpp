Ques Link :- "https://leetcode.com/problems/maximum-width-of-binary-tree/description/"



HINT :-
1 - level order traversal





















2 - level ke nodes ko numbering dena chaku karo

























3 - numbering according to if numbering given to parent node is 'i' then left = 2i+1, right=2i+2




























4 - overflow se bachne ke liye min numbering i.e. min numbering jo thi uss level ki usko saare level ki numbering me se substract kardo

























CODE:-
class Solution {
    public:
        int widthOfBinaryTree(TreeNode* root) {
            if(root ==NULL)return 0;
            queue<pair<TreeNode*,int>>q;
            q.push({root,0});
            int maxans=0;
            while(!q.empty()){
                int size=q.size();
                int mini = q.front().second;
                int first,last;
                for(int i=0;i<size;i++){
                    TreeNode* node = q.front().first;
                    long x = (q.front().second)-mini;q.pop();
                    
                    if(i==0)first=x;
                    if(i==size-1)last=x;
    
                    if(node->left) {q.push({node->left, 2*x+1});}
                    if(node->right){q.push({node->right,2*x+2});}
    
                }
                maxans = max(maxans,last-first+1);
            }
            return maxans;
        }
};