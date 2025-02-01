Prob Link: "https://leetcode.com/problems/remove-outermost-parentheses/description/"

Hint :- 
    with space -> use stack to maintain check of first bracket i.e. to be removed with 'ans' string
    without space -> maintain a counter 'ct' to check first bracket .........(same)................


























CODE:-
    with space -> 
        class Solution {
        public:
            string removeOuterParentheses(string s) {
                int n=s.size();
                string ans;stack<int>st;
                for(int i=0;i<n;i++){
                    
                    if(s[i]==')')st.pop();
                    //if string is empty
                    if(!st.empty()){
                        if(s[i]=='(')st.push('(');
                        ans += s[i];
                    }
                    else if(s[i]=='(')st.push('(');
                    
                }
            return ans;
            }
        };



    without space :- (2 codes for this -> both have fully same intuition but differ in logic , -> as one code is checking if ct==0 then dont add/remove anything from ans , otherwise add to answer and maintain ct & 
    
    -> other code focusing on if ct==1 then we have to be careful whether the current bracket is primary closing or not if yes then dont add it to ans -> more u can understand from code)

        class Solution {
        public:
            string removeOuterParentheses(string s) {
                int n=s.size();
                string ans;int ct=0;
                for(int i=0;i<n;i++){
                    if(ct==0)ct++;
                    else {if(s[i]=='(')ct++;
                        else ct--;
                        if(ct!=0)ans += s[i];
                    }
                }
            return ans;
            }
        };