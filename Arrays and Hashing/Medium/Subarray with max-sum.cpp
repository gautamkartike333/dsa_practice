// Problem Link="https://leetcode.com/problems/maximum-subarray/"

This ques is solved by Kadane's Algorithm

Steps:-
    Step-1: sum karte jao har element ka  
    Step-2: maxsum ko update karte jao if sum>maxsum
    Step-3: but REMEMBER ki -ve sum ko aage carry-on karne se sum ghatega hi bhadega nahi , jese maan lo index 3 par sum=-2 , toh agar  ham -2 ko aage leke jaaenge toh sum ghatega bcoz it is a -ve number , toh behtar ye hoga ki jab sum -ve ho tab sum=0 set kardo.

CODE:
        class Solution {
        public:
            int maxSubArray(vector<int>& nums) {
                int n=nums.size();
                int sum=INT_MIN,maxsum=INT_MIN;
            for(int i=0;i<n;i++){
                    if(sum<0)sum=0;
                    sum+=nums[i];
                    maxsum=max(maxsum,sum);
            }
            return maxsum;
            }
        };

Agar subarray hi print karwana ho tab:

        class Solution {
        public:
            int maxSubArray(vector<int>& nums) {
                int n=nums.size();
                int sum=INT_MIN,maxsum=INT_MIN,starti=-1,endi=-1;
            for(int i=0;i<n;i++){
                    if(sum<0)sum=0;
                    if(sum==0)starti=i;
                    sum+=nums[i];
                    if(sum>maxsum){maxsum=sum;endi=i;}
                    maxsum=max(maxsum,sum);
            }
            return maxsum;
            }
        };
