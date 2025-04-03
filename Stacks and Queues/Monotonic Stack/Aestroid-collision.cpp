Ques Link :"https://leetcode.com/problems/asteroid-collision/description/"

HINT: dekho jab -ve element aaega tab dikkat hai , +ve toh push karte jao 





























Code-
class Solution {
    public:
        vector<int> asteroidCollision(vector<int>& arr) {
            int n=arr.size();
            stack<int>st;
    
            for(int i=0;i<n;i++)
            {
                if(arr[i]>0) st.push(arr[i]);
                else {
                    //arr[i]<0
                    while(!st.empty() && st.top()>0 && abs(st.top())<abs(arr[i]))
                    st.pop();
                    if(!st.empty() && st.top()==abs(arr[i]))st.pop();
                    else if(st.empty() || st.top()<0)st.push(arr[i]);
                    
                }
    
            }
            vector<int>ans;
            while(!st.empty()){
            ans.push_back(st.top());st.pop();}
            reverse(ans.begin(),ans.end());
            return ans;
        }
    };