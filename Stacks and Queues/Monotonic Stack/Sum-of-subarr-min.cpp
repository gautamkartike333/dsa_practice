Ques Link:"https://leetcode.com/problems/sum-of-subarray-minimums/description/"


Solution:
class Solution {
    public:
        vector<int>nse(int i,vector<int>& arr,int n)
        {
            vector<int>ans(n,-1);
            stack<int>st;
    
            for(int i=n-1;i>=0;i--){
                while(!st.empty() && arr[st.top()]>=arr[i] )st.pop();
                ans[i]=st.empty()?n:st.top();
                st.push(i);
            }
            return ans;
        }
        vector<int>psee(int i,vector<int>& arr,int n)
        {
            vector<int>ans(n,-1);
            stack<int>st;
    
            for(int i=0;i<n;i++){
                while(!st.empty() && arr[st.top()]>arr[i] )st.pop();
                ans[i]=st.empty()?-1:st.top();
                st.push(i);
            }
            return ans;
        }
        int sumSubarrayMins(vector<int>& arr) {
            int mod = int(1e9+7);
            int n=arr.size();
            int sum=0;
            vector<int>nans=nse(0,arr,n);
            vector<int>pans=psee(0,arr,n);
            long long total=0;
            for(int i=0;i<n;i++){
                int left = i-pans[i];
                int right= nans[i]-i;
                total = ((total + (left*right*1LL*arr[i])%mod))%mod;
    
            }
    
            return total;
        }
};