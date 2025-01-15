Prob Link:"https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1"

CODE:-
        class Solution {
            // Function to find the leaders in the array.
        public:
            vector<int> leaders(vector<int>& arr) {
                // Code here
                int n=arr.size();
                vector<int>ans;
                int maxel=INT_MIN;
                for(int i=n-1;i>=0;i--){
                    if(arr[i]>=maxel){
                        ans.push_back(arr[i]);
                        maxel=arr[i];
                    }
                }
                // reverse(ans.begin(),ans.end());
                return ans;
            }
        };