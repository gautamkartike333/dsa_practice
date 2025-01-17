Prob Link:-"https://leetcode.com/problems/subarray-sum-equals-k/"

Better Solution:-
    T.C.-> O(N^2)
    generating all the subarrays & checking their sum is equals to the target or not 
    If yes, then ct++;
    CODE:-
            int findAllSubarraysWithGivenSum(vector < int > & arr, int k) {
            int n = arr.size(); // size of the given array.
            int cnt = 0; // Number of subarrays:

            for (int i = 0 ; i < n; i++) { // starting index i
                int sum = 0;
                for (int j = i; j < n; j++) { // ending index j
                    // calculate the sum of subarray [i...j]
                    // sum of [i..j-1] + arr[j]
                    sum += arr[j];

                    // Increase the count if sum == k:
                    if (sum == k)
                        cnt++;
                }
            }
            return cnt;
        }

Optimal soln:-
    Using hashMap
    
        Steps
        Step-1:- hashMap banalo ek, and usme prefixSum add karte jao  
        Step-2:- Note:- If current prefixSum-k exists in mapp then (and map ki value me cnt store karo ki wo kitni baar pehle aa chuka hai) cnt+=mapp[sum-k]
            Return cnt;
    CODE:-
        int subarraySum(vector<int>& nums, int k) {
            int n=nums.size();int ct=0,sum=0;
            map<int,int>mapp;
            mapp[0]=1;
            for(int i=0;i<n;i++){
                sum+=nums[i];
                if(mapp.find(sum-k)!=mapp.end())ct=ct+mapp[sum-k];
                mapp[sum]++;;

            }
            return ct;
        }