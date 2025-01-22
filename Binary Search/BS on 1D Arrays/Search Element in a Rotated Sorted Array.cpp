Search el in rotated sorted array-2 ->iss  wale ko karo toh isase pehle wala search el in rotated sorted arr-1 automatically ho jaaega
Prob Link:-"https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/"

Hint:-
    Hint:check which half is sorted
(bas yahi hint hai isase toh pura ques ho jaaega)




Solution:- (neeche)






















Code:-
        class Solution {
        public:
            int search(vector<int>& nums, int target) {
                int n=nums.size();
                int l=0,r=n-1,mid,ans=-1;
                while(l<=r){
                    mid=(l+r)/2;
                    if(nums[mid]==target){return mid;}
                    //checking if arr is sorted
                    else if(nums[l]<=nums[mid]){
                            if(target <= nums[mid] && target>= nums[l])r=mid-1;
                            else l=mid+1;
                    }
                    else{ 
                    if(target <= nums[r] && target>= nums[mid]) l=mid+1; 
                            else r=mid-1;
                    }
                
                }
            return -1;
            }
        };