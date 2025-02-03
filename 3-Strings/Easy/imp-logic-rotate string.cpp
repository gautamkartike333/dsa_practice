Prob Link: "https://leetcode.com/problems/rotate-string/description/"

Hints:-
    O(N^2)rotate karo ek ek karke then check karo goal ke equal hua ki nahi.bas
    
    Optimal:- 
    
    Brute Force CODE:-
        class Solution {
        public:
            string rotatest(int k,string st,int n){
                string s=st;
                for(int j=k;j<=n-1+k;j++){
                    s[j-k]=st[j%n];
                }
                return s;
            } 
            bool rotateString(string s, string goal) {
                int ssize=s.size(),gsize=goal.size();
                if(ssize != gsize)return false;
                if(s==goal)return true;
                for(int i=1;i<ssize;i++){
                    if( rotatest(i,s,ssize) == goal)return true;

                }
                return false;
            }
        };
            
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
        Optimal:- when we concatenate a string n itself then , it contains all the rotations as a substring in it....


        bool rotateString(string s, string goal) {
        int ssize=s.size(),gsize=goal.size();
        if(ssize != gsize)return false;
        if(s==goal)return true;
        s=s+s;
        if(s.find(goal) != string::npos)return true;
        return false;
    
         }