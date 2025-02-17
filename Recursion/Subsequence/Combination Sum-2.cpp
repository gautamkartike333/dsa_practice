Prob Link : "https://leetcode.com/problems/combination-sum-ii/description/"



Hint -1:- Striver ke solution ko mat dekho , wo galt hai , jese tumne combination sum-1 kiya hai , bas usi me try karo.
Hint -2:- Ab kya karo ye sochna hai , kuch esa karo ki saare duplicates ek hi jagah aa jaye , baaki fir uske baad toh condition check lagake unhe skip toh kar hi sakte ho recursion ke time

































Hint -3:- sort initial candidates array





























Hint -4:- now skip duplicates el. in recursion by check if arr[i]==arr[i-1] then i-- ; and move on 


























CODE:-
        class Solution {
            public:
            void solve(int i , vector<int>& arr , int target , vector<vector<int>>&ans,vector<int>& ds){
                    if (target == 0) {
                        ans.push_back(ds);
                        return;
                    }
                    if(i==-1)return;
                    if(target<0)return;
                    //pick
                    ds.push_back(arr[i]);
                    solve(i-1,arr,target-arr[i],ans,ds);
                    ds.pop_back();
                    while(i>0 && arr[i]==arr[i-1])i--;
            
                    solve(i-1,arr,target,ans,ds);
            
            
                }
                vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
                    int n=candidates.size();
                    sort(candidates.begin(),candidates.end());
                    vector<vector<int>>ans;
                    vector<int> temp;
                    solve(n-1,candidates,target,ans,temp);
                    return ans;
                }
        };