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
