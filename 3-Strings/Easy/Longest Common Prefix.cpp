Prob Link: "https://leetcode.com/problems/longest-common-prefix/description/"

CODE:- 
        string longestCommonPrefix(vector<string>& strs) {
            int n=strs.size();
            if(n==1)return strs[0];
            sort(strs.begin(),strs.end());
            string first = strs[0];
            string last = strs[n-1];
            int i=0;
            string ans="";
            n = first.size()<last.size() ? first.size() : last.size();
            while(i<n){
                if(first[i]!=last[i])break;
                else {ans += first[i];}
                i++;
            }
            return ans;
        }