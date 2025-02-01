Prob Link: "https://leetcode.com/problems/isomorphic-strings/description/"



Code:- 
        bool isIsomorphic(string s, string t) {
            int ssize=s.size();
            int tsize=t.size();
            if(ssize!=tsize)return false;
            unordered_map<char,char>mapp;

            for(int i=0;i<ssize;i++){
                if(mapp.find(s[i]) != mapp.end()){
                    if(mapp[s[i]]!=t[i])return false;
                    else continue;
                }
                mapp[s[i]]=t[i];
            }
            mapp.clear();
            for(int i=0;i<ssize;i++){
                if(mapp.find(t[i]) != mapp.end()){
                    if(mapp[t[i]]!=s[i])return false;
                    else continue;
                }
                mapp[t[i]]=s[i];
            }        
        
        return true;
        }