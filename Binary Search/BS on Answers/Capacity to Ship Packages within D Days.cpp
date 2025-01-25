Prob Link : "https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/"

    CODE : -

                   class Solution
{
public:
    bool checkValid(vector<int> weights, int mid, int days)
    {
        int n = weights.size(), ans = mid, dayct = 1;
        for (int i = 0; i < n; i++)
        {
            if (ans < weights[i])
            {
                dayct++;
                ans = mid;
            }
            if (dayct > days)
                return false;
            ans = ans - weights[i];
        }
        return dayct <= days;
    }
    int shipWithinDays(vector<int> &weights, int days)
    {
        int n = weights.size();
        int sum = 0, maxel = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            sum += weights[i];
            maxel = max(maxel, weights[i]);
        }
        int l = maxel, r = sum, mid, ans = INT_MAX;
        // if (checkValid(weights, 11, 5)){cout<<"yes"<<endl;}
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (checkValid(weights, mid, days))
            {
                cout << "l=" << l << " r=" << r << endl;
                ans = min(ans, mid);
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return l;
    }
};