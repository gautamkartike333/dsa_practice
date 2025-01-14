//Ques link="https://leetcode.com/problems/two-sum/description/"

//Solution:-
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       map<int,int>mapp;int n=nums.size();
       
       int x,y;
       for(int i=0;i<n;i++){
            if(mapp.find(target-nums[i]) != mapp.end()){
                x=i;
                y=mapp[target-nums[i]];break;
              } 
              mapp[nums[i]]=i;
               }
       return {x,y};
       }
};
/*
If we only wantto return yes/no then:-
  Use 2 pointer approach :-
    Step-1:-Sort the Array
    Step-2:-Put left pointer at 0th index and reght pointer at (n-1)th index
    Step-3:-If arr[left]+arr[right]>target right-- else left++
    Step-4:-If arr[left]+arr[right]==target return yes at last return No
*/
