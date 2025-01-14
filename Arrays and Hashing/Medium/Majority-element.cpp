// Problem Link:-"https://leetcode.com/problems/majority-element/description/"


Better Approach-Using hashmap
Code:-
        class Solution {
        public:
            int majorityElement(vector<int>& nums) {
                unordered_map<int,int>mapp;
            for(auto it:nums){
                mapp[it]++;
            }
            int n=nums.size();
            // auto ansi;
            for(int i=0;i<n;i++){
                if(mapp[nums[i]]>(n/2))return nums[i];
            }
            return 1;
            }
        };


//Optimal Approach:-
    Moore’s Voting Algorithm:
    CODE:-
    class Solution {
        public:
            int majorityElement(vector<int>& nums) {
            int n=nums.size();
            int element=nums[0];
            int ct=0;
            for(int i=0;i<n;i++){
                if(ct==0)element=nums[i];
                if(nums[i]==element)ct++;
                else ct--;
            }
            return element;
            }
        };