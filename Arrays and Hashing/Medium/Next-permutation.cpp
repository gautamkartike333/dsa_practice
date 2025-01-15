// Problem Link: "https://leetcode.com/problems/next-permutation/description/"

CODE:-
            class Solution {
            public:
                void nextPermutation(vector<int>& nums) {
                    int n=nums.size();int brkpt=-1;
                    int minel=INT_MAX,minj=INT_MAX;

                    if(n>1){for(int i=n-2;i>=0;i--){
                        if(nums[i]<nums[i+1]){brkpt=i;break;}
                    }
                if(brkpt==-1){reverse(nums.begin(),nums.end());}
                else{
                    for(int i=n-1;i>0;i--){
                        if(nums[i]>nums[brkpt]){
                            swap(nums[i],nums[brkpt]);
                            reverse(nums.begin()+brkpt+1,nums.end());
                            break;
                        }
                    }
                // swap(nums[brkpt],nums[minj]);
                // sort(nums.begin()+brkpt+1,nums.end());
                }
            }
                }
            };