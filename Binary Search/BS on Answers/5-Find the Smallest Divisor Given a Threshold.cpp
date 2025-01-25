Prob Link:"https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/"


CODE:-
        class Solution {
        public:
            bool checkValid(vector<int> nums, int mid, int th) {
                int n = nums.size();
                int ans = 0;
                for (int i = 0; i < n; i++) {
                    ans += ceil((double)nums[i] / mid);
                    if (ans > th)
                        return false;
                }
                if (ans <= th)
                    return true;
                return false;
            }
            int smallestDivisor(vector<int>& nums, int threshold) {
                int n = nums.size();
                int minel = INT_MAX, maxel = INT_MIN;
                for (int i = 0; i < n; i++) {
                    maxel = max(maxel, nums[i]);
                    minel = min(minel, nums[i]);
                }
                int l = 1, r = maxel, mid;
                while (l <= r) {
                    mid = l + (r - l) / 2;
                    if (checkValid(nums, mid, threshold))
                        r = mid - 1;
                    else
                        l = mid + 1;
                }
                return l;
            }
        };