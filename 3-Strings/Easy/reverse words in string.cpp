Prob Link: "https://leetcode.com/problems/reverse-words-in-a-string/description/"

CODE:-
        string reverseWords(string s) {
            string temp="",ans="";
            int n=s.size();
            int i=n-1;
            while(i>=0){ 
                // ans += ' ';
                while(i>=0 && s[i]==' ') i--;

                if(i<0)break;
                while(i>=0 && s[i]!=' '){
                    temp += s[i];i--;
                }
                // while(i>=0 && s[i]==' '){ i--;}
                reverse(temp.begin(),temp.end());
                // temp += ' ';
                if(!ans.empty())ans += ' ';
                ans += temp;
                temp="";
            }
        return ans;
        }