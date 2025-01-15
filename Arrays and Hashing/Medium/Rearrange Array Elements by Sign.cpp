Prob Link: "https://leetcode.com/problems/rearrange-array-elements-by-sign/description/"

Variety-1 Ques
    If size is even     
        CODE:-
            vector<int> alternateNumbers(vector<int>&nums) {
            int n = nums.size();
                int i = 0, j = 0;
                bool x = true;
                vector<int> ans;
                while (i < n && j < n) {
                    while (nums[i] < 0 && x == true)
                        i++;
                    if (nums[i] > 0) {
                        ans.push_back(nums[i]);
                        i++;
                        x = false;
                    }
                    while (nums[j] > 0 && x == false)
                        j++;
                    if (nums[j] < 0) {
                        ans.push_back(nums[j]);
                        j++;
                        x = true;
                    }
                }

                return ans;
             }

Variety-2 Ques->{This solution is good then striver's solution}
    If size is odd (some +ve or -ve elements are left bcoz they are more in nos then their opposite sign)     
        CODE:-
                #include<bits/stdc++.h>
                using namespace std;

                vector<int> alternateNumbers(vector<int>&nums) {
                    int n = nums.size();
                        int i = 0, j = 0;
                        bool x = true;
                        vector<int> ans;
                        while (i < n && j < n) {
                            while (nums[i] < 0 && x == true)
                                i++;
                            if (nums[i] > 0) {
                                ans.push_back(nums[i]);
                                i++;
                                x = false;
                            }
                            while (nums[j] > 0 && x == false)
                                j++;
                            if (nums[j] < 0) {
                                ans.push_back(nums[j]);
                                j++;
                                x = true;
                            }
                        }
                        while(i<n)ans.push_back(nums[i++]);
                        while(j<n)ans.push_back(nums[j++]);

                        return ans;
                }

                int main(){
                    vector<int> arr={3,1,-2,-5,-6,-8,-5,9};
                    vector<int>answer=alternateNumbers(arr);
                    for(int i=0;i<8;i++)cout<<answer[i]<<" , ";
                }