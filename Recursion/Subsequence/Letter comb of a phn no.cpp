Prob Link : "https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/"

Hint :- jyada dimaag mat lagao , bas jese combination sum wale questions kiye h , ek temp string banalo , then push kardo recursion call karo next index ke liye , then pop kardo wapas aake , 




























CODE:-
        class Solution {
        public:
        void solve(int i,unordered_map<char,string>mapp,string digits,string&temp,vector<string>&ans){
        
                if(i==digits.size()){
                    ans.push_back(temp);
                    return;
                }
        
                string str = mapp[digits[i]];
                
                for(int j=0;j<str.size();j++){
                    temp.push_back(str[j]);
                    solve(i+1,mapp,digits,temp,ans);
                    temp.pop_back();
                }
        
            }
            vector<string> letterCombinations(string digits) {
        
                unordered_map<char,string>mapp;
                mapp['2']="abc";
                mapp['3']="def";
                mapp['4']="ghi";
                mapp['5']="jkl";
                mapp['6']="mno";
                mapp['7']="pqrs";
                mapp['8']="tuv";
                mapp['9']="wxyz";
                vector<string>ans;
                string temp;
                if(digits.size()==0) return ans;
                solve(0,mapp,digits,temp,ans);
                return ans;
            }
        };