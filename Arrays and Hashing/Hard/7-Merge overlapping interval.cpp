Prob Link : "https://leetcode.com/problems/merge-intervals/"


T.C. : O(nlogn)+O(n)
S.S. : O(N) ->to store ans arr.
Steps:
    Step-1: Pehle sort karlo intervals ko according to first el of vector that is inside interval (if 1st el is equal then sort acc to 2nd el)
    Step-2: ab ek v<v<int>>ans banalo usme start el and end time el ko push kardo , ab aage badho and dekho ki start of curr el end time of old el se chota h ya bada agaroverlap kare toh end ko update kardo acc to konsa bada hai purana end ya curr el ka end 
    Step-3: Agar overlap nahi kr rha toh simply aage badh jao usse vector me push karke .

CODE:
        vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr) {
        int n = arr.size(); // size of the array

        //sort the given intervals:
        sort(arr.begin(), arr.end());

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            // if the current interval does not
            // lie in the last interval:
            if (ans.empty() || arr[i][0] > ans.back()[1]) {
                ans.push_back(arr[i]);
            }
            // if the current interval
            // lies in the last interval:
            else {
                ans.back()[1] = max(ans.back()[1], arr[i][1]);
            }
        }
        return ans;
        }
