//Problem link="https://leetcode.com/problems/sort-colors/description/"

/*
As ques suggested to not too do ques by sorting the Array, Do in one pass loop  i.e. T.C.=O(N)
    So, only Solution left is Dutch National flag algorithm
*/

/*
This algorithm contains 3 pointers i.e. low, mid, and high, and 3 main rules.  The rules are the following:

arr[0….low-1] contains 0. [Extreme left part]
arr[low….mid-1] contains 1.
arr[high+1….n-1] contains 2. [Extreme right part], n = size of the array
The middle part i.e. arr[mid….high] is the unsorted segment.

*/

/*
There can be three different values of mid pointer i.e. arr[mid]
    =>If arr[mid] == 0, we will swap arr[low] and arr[mid] and will increment both low and mid. Now the subarray from index 0 to (low-1) only contains 0.
    =>If arr[mid] == 1, we will just increment the mid pointer and then the index (mid-1) will point to 1 as it should according to the rules.
    =>If arr[mid] == 2, we will swap arr[mid] and arr[high] and will decrement high. Now the subarray from index high+1 to (n-1) only contains 2.
    In this step, we will do nothing to the mid-pointer as even after swapping, the subarray from mid to high(after decrementing high) might be unsorted. So, we will check the value of mid again in the next iteration.
Finally, Array is sorted

*/

//CODE:-

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int mid=0,low=0,high=n-1;
        while(mid<=high){
            if(nums[mid]==0){swap(nums[mid],nums[low]);low++;mid++;}
            else if(nums[mid]==1){mid++;}
            else{swap(nums[mid],nums[high]);high--;}
        }

    }
};