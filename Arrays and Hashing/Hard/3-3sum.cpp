Prob Link:"https://leetcode.com/problems/3sum/"

Steps for optimal->
    Step-as similar in 2sum problem we have sorted arr, and putted i and j pointers at 0,n-1 index.
    Same , here but first fix one index , then put j at fixed index+1 and k at last index.
    remember that we have to skip duplicates , so when we get 3_el_sum==0 then put it in ans v<v<int>>, 
    but skip duplicate elements , ->move j++ until we find different el and k-- vice versa

    CODE:
        vector<vector<int>> threeSum(vector<int>& nums) {
            vector<vector<int>>ans; int n=nums.size();
            sort(nums.begin(),nums.end());
        
            for(int i=0;i<n;i++){
                if(i>0 && (nums[i]==nums[i-1])){continue;}
                int j=i+1,k=n-1;
                while(j<k){
                    int sums=nums[i]+nums[j]+nums[k];
                    if(sums>0){
                        k--;
                    }
                    else if(sums<0){
                        j++;
                    }
                    else{
                        vector<int>temp={nums[i],nums[j],nums[k]};
                        ans.push_back(temp);
                        j++;k--;
                        while(j<k && nums[j]==nums[j-1])j++;
                        while(j<k && nums[k]==nums[k+1])k--;

                    }
                }
            }
            return ans;
        }