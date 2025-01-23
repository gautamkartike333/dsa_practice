    Prob Link:"https://leetcode.com/problems/single-element-in-a-sorted-array/"

Hint:
    Jo single el hai , uske left and right half ko chota karne ki socho ->haan mujhe pata hai tum yhi soch rhe ho kaise?? but iska ans mil gya toh ques hi solve ho jaaega fir toh -> isiliye socho-socho dont look solution
























CODE:-


int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=n-1,mid;
        if(n==1 || nums[0]!=nums[1])return nums[0];
        if(nums[n-2]!=nums[n-1])return nums[n-1];
        l=1;r=n-2;
        while(l<=r){
            mid=(l+r)/2;
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1])return nums[mid];
            else if ((mid % 2 == 1 && nums[mid] == nums[mid - 1])
                        || (mid % 2 == 0 && nums[mid] == nums[mid + 1]))l=mid+1;
            else r=mid-1;
        }
            return -1;
            }