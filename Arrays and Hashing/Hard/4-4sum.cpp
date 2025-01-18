Prob Link:-"https://leetcode.com/problems/4sum/"

Optimal solution : Just like 2-sum & 3-sum , here there will be 4 pointers i,j,k,l
                   We will fix i,j and move k,l (i and j ki loop lag jaaegi ), remember to skip duplicates

    CODE:-
        vector<vector<int>> fourSum(vector<int>& nums, int target) {
            int n=nums.size();sort(nums.begin(),nums.end());
            int a,b,c,d;
            vector<vector<int>>ans;
            for(int i=0;i<n;i++){
                if(i!=0 && nums[i]==nums[i-1])continue;
                for(int j=i+1;j<n;j++){
                    if(j!=i+1 && nums[j]==nums[j-1])continue;
                    int k=j+1,l=n-1;
                    while(k<l){
                        //this adding up like this is done to avoid int overflow , (the max limit of int range)
                        long long sum = nums[i];
                        sum += nums[j];
                        sum += nums[k];
                        sum += nums[l];
                        
                        if(sum > target)l--;
                        else if(sum < target)k++;
                        else {
                            // cout<<"i="<<i<<"j="<<j<<"k="<<k<<"l="<<l<<endl;
                            vector<int>temp={nums[i],nums[j],nums[k],nums[l]};
                            ans.push_back(temp);
                            k++;l--;
                            while(k<l && nums[k]==nums[k-1])k++;
                            while(k<l && nums[l]==nums[l+1])l--;
                        }
                        
                    }

                }
            }
        return ans;
        }