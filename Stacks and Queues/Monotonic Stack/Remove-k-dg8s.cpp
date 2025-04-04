Ques Link :"https://leetcode.com/problems/remove-k-digits/description/"

HINT :- 
1 - use stack to solve this ques

2 - stack ke top pe agar bada el hai toh pop kardo , pop karne se pehle ye dekh lena ki k>0 ho.









































CODE:-
class Solution {
    public:
        string removeKdigits(string nums, int k) {
            int n=nums.size();
            int j=0;
            if(k>=n)return "0";
            if(nums[j]=='0'){
                while(nums[j]=='0')j++;
            }
            stack<int>st;
            cout<<"j="<<j<<endl;
            for(int i=j;i<n;i++){
                while(!st.empty() && (st.top()-'0')>(nums[i]-'0') && k>0)
                {   st.pop();k--;}
                st.push(nums[i]);
            }
            
            while(k>0){st.pop();k--;}
            if(st.empty())return "0";
            
            string ans="";
            
            while(!st.empty() ){
                ans+=st.top();
                st.pop();
            }
            while(!ans.empty() && ans.back()=='0'){ans.pop_back();}
            reverse(ans.begin(),ans.end());
            if(ans.empty())return "0";
            return ans;
        }
    };