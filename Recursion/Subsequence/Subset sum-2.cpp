Note - dont see solution submintted on leetcode -> see below code for optimal version

Prob Link : "https://www.naukri.com/code360/problems/unique-subsets_3625236?leftPanelTabValue=PROBLEM"











Hint :- same as combination sum-2 





























hint-2 : try to skip duplicates 



























hint-3 :- dont traverse array from back , bcoz you want sorted answer , if you traverse it from back , then you have to again sort the array before inserting it to answer 



























CODE:-
        #include <bits/stdc++.h> 
        using namespace std;
        void solve(int i, vector<int>&nums,vector<int>& temp, vector<vector<int>>& ans){
                if(i>=nums.size()){
                    // sort(temp.begin(),temp.end());
                    ans.push_back(temp);return ;
                    }

                //pick
                else {temp.push_back(nums[i]);
                solve(i+1,nums,temp,ans);
                temp.pop_back();
                //notpick
                while(i+1<nums.size() && nums[i]==nums[i+1])i++;
                solve(i+1,nums,temp,ans);}

            }

        vector<vector<int>> uniqueSubsets(int n, vector<int> &nums)
        {

                sort(nums.begin(),nums.end());
                vector<vector<int>> ans;
                vector<int>temp;
                solve(0,nums,temp,ans);
                sort(ans.begin(),ans.end());

                return ans;
        }