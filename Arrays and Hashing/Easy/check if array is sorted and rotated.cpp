

Hint :-
    hint-1: check no. of invalid pairs .






























    hint-2: no. of invalid pairs should be <=1 


























    CODE:- 

        class Solution {
            public:
                bool check(vector<int>& nums) {
                int n=nums.size();int ct=0;
                
                for(int i=1;i<n;i++){
                    if(nums[i-1]>nums[i])ct++;
            
                }
                if(nums[n-1]>nums[0])ct++;
                return ct<=1;
                }
            };