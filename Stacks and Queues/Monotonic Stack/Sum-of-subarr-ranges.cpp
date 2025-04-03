Ques Link -:"https://leetcode.com/problems/sum-of-subarray-ranges/description/"


Hint:-
aap agar saare subaarays likhenge and fir un sabme (largest-smallest) likhoge , then summation(largest-smallest) karoge toh ,
mathematical property se ise todlo summation(largest)-summation(smallest).

And second thing is that ki , aap summation(smallest) toh pehle hi nikal chuke ho , simimlar tarike se aap summation(largest) nikal sakte ho..








































CODE:-
class Solution {
    public:
        vector<int>nsefxn(vector<int>&nums){
            int n=nums.size();
            vector<int>ans(n,-1);
            stack<int>st;
    
            for(int i=n-1;i>=0;i--){
                while(!st.empty() && nums[st.top()]>=nums[i])st.pop();
                ans[i]=st.empty()?n:st.top();
                st.push(i);
            }
            return ans;
        }
    
        vector<int>ngefxn(vector<int>&nums){
            int n=nums.size();
            vector<int>ans(n,-1);
            stack<int>st;
    
            for(int i=n-1;i>=0;i--){
                while(!st.empty() && nums[st.top()]<=nums[i])st.pop();
                ans[i]=st.empty()?n:st.top();
                st.push(i);
            }
            return ans;
        }
    
        vector<int>psefxn(vector<int>&nums){
            int n=nums.size();
            vector<int>ans(n,-1);
            stack<int>st;
    
            for(int i=0;i<n;i++){
                while(!st.empty() && nums[st.top()]>nums[i])st.pop();
                ans[i]=st.empty()?-1:st.top();
                st.push(i);
            }
            return ans;
        }
        vector<int>pgefxn(vector<int>&nums){
            int n=nums.size();
            vector<int>ans(n,-1);
            stack<int>st;
    
            for(int i=0;i<n;i++){
                while(!st.empty() && nums[st.top()]<nums[i])st.pop();
                ans[i]=st.empty()?-1:st.top();
                st.push(i);
            }
            return ans;
        }
    
        long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        vector<int>nse=nsefxn(nums);
        vector<int>pse=psefxn(nums);
        vector<int>nge=ngefxn(nums);
        vector<int>pge=pgefxn(nums);
        long long contri_min=0;
        long long contri_max=0;
        for(int i=0;i<n;i++){
            contri_min+=((nse[i]-i)*(i-pse[i])*1LL*nums[i]);
            contri_max+=((nge[i]-i)*(i-pge[i])*1LL*nums[i]);
        }
        return contri_max-contri_min;
        }
};