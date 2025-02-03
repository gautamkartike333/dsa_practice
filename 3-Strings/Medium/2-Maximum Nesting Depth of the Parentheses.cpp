Prob Link:-"https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/description/"


CODE:-
    it is the most optinmal code :-
    
            int maxDepth(string s) {
                int ct=0;int ans=0;
                for(auto it:s){
                    if(it=='('){
                        ct++;
                        ans=max(ans,ct);}
                    else if(it==')'){
                            ct--; 
                    }
                }
                return ans;
            }
